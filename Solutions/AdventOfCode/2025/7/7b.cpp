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
    
    vector<lint> beem;
    for (auto i : v[0]) {
        if (i == 'S') {
            beem.pb(1);
        }
        else {
            beem.pb(0);
        }
    }

    for (int i = 1; i < n; i ++) {
        for (int j = 0; j < v[i].size(); j ++) {

            if (v[i][j] == '^') {
                if (beem[j] > 0) {

                    if (j-1 >= 0) {
                        beem[j-1] += beem[j];
                    }
                    if (j+1 < v[i].size()) {
                        beem[j+1] += beem[j];
                    }

                    beem[j] = 0;

                }
            }

        }
    }

    lint ans = 0;
    for (int i = 0; i < v[0].size(); i ++) {
        ans += beem[i];
    }

    cout << ans << endl;
}

// correct ans: 1537373473728