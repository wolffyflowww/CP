// author: ZH-170
// created: 01 Dec 2025 16:41

#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        string f; cin >> f; freopen(f.c_str(), "r", stdin); cout << endl;
    #endif

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int cur = 50, cnt = 0;
    int n = 4629;
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        int f = 1;
        if (s[0] == 'L') {
            f = -1;
        }

        int num = 0;
        for (int i = 1; i < s.size(); i ++) {
            num += (int(s[i])-48)*pow(10, s.size()-i-1);
        }
        
        cur += (f*num);
        cur %= 100;

        if (cur == 0) {
            cnt ++;
        }
    }

    cout << cnt;

}

// correct ans: 1154