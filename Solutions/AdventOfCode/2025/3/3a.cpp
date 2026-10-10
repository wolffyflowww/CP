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

    int ans = 0;
    while (n --) {
        string s;
        cin >> s;

        int m1 = -1, m1i = -1;
        for (int i = 0; i < s.size(); i ++) {
            if (int(s[i]) - 48 > m1) {
                m1 = int(s[i])-48;
                m1i = i;
            }
        }

        if (m1i == s.size()-1) {
            int m2 = 0;
            for (int i = 0; i < s.size()-1; i ++) {
                m2 = max(m2, int(s[i])-48);
            }

            ans += (m2*10) + m1;
        }
        else {
            int m2 = -1;
            for (int i = m1i + 1; i < s.size(); i ++) {
                m2 = max(m2, int(s[i])-48);
            }

            ans += (m1*10) + m2;
        }

    }

    cout << ans << endl;
}

// correct ans: 17452