// author: ZH-170
// created: 01 Dec 2025 22:29

#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        string f; cin >> f; freopen(f.c_str(), "r", stdin); cout << endl;
    #endif

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n = 1176, m = 209;
    vector<vector<int>> v(101, vector<int>(101, 0));

    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;

        int a = (int(s[0])-48)*10 + (int(s[1])-48), b = (int(s[3])-48)*10 + (int(s[4])-48);
        v[a][b] = 1;
    }
    
    int ans = 0;
    while (m--) {
        string s;
        cin >> s;

        vector<int> ls;
        for (int i = 0; i < s.size()-1; i += 3) {
            int x =  (int(s[i])-48)*10 + (int(s[i+1])-48);
            ls.pb(x);
        }

        bool is_valid = true;
        for (int i = 1; i < ls.size(); i ++) {
            for (int j = 0; j < i; j ++) {
                if (v[ls[i]][ls[j]] == 1) {
                    is_valid = false;
                    break;
                }
            }
            if (!is_valid) {
                break;
            }
        }

        if (is_valid) {
            ans += ls[ls.size()/2];
        }

    }

    cout << ans << endl;
    
}


// correct ans: 5747