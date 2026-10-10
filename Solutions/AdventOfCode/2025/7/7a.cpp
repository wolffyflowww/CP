// author: ZH-170
// created: 08 Dec 2025 01:33

#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        string f; cin >> f; freopen(f.c_str(), "r", stdin); cout << endl;
    #endif

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    n = 142;

    vector<string> v;
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;

        v.pb(s);
    }
    
    vector<bool> has_beem;
    for (auto i : v[0]) {
        if (i == 'S') {
            has_beem.pb(true);
        }
        else {
            has_beem.pb(false);
        }
    }

    int ans = 0;
    for (int i = 1; i < n; i ++) {
        for (int j = 0; j < v[i].size(); j ++) {
            if (v[i][j] == '^') {
                if (has_beem[j]) {
                    ans ++;
                    has_beem[j] = false;

                    if (j-1 >= 0) {
                        has_beem[j-1] = true;
                    }
                    if (j+1 < v[i].size()) {
                        has_beem[j+1] = true;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}

// correct ans: 1507