// author: ZH-170
// created: 03 Dec 2025 22:24

#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        string f; cin >> f; freopen(f.c_str(), "r", stdin); cout << endl;
    #endif

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n = 200;

    lint ans = 0;
    while (n --) {
        string s;
        cin >> s;

        lint sum = 0;
        int cur_start = 0;
        for (int i = 12; i >= 1; i --) {
            
            int m1 = -1, m1i = -1;
            for (int j = cur_start; j < s.size()-i+1; j ++) {
                if (int(s[j])-48 > m1) {
                    m1 = int(s[j])-48;
                    m1i = j;
                }
            }

            sum += (m1 * pow(10, i-1));
            cur_start = m1i + 1;
        }

        ans += sum;

    }

    cout << ans << endl;
}

// correct ans: 173300819005913