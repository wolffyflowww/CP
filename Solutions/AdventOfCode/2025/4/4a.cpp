// author: ZH-170
// created: 04 Dec 2025 22:38

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
    n = 135;

    vector<string> v;
    string first_row;
    cin >> first_row;
    
    first_row = '.' + first_row + '.';
    string empty_row = "";
    for (auto i : first_row) {
        empty_row += '.';
    }

    v.pb(empty_row);
    v.pb(first_row);
    for (int i = 1; i < n; i ++) {
        string row;
        cin >> row;

        row = '.' + row + '.';
        v.pb(row);
    }
    v.pb(empty_row);

    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    int ans = 0;

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j < first_row.size()-1; j ++) {

            if (v[i][j] == '@') {
                
                int cnt = 0;
                for (int ii = 0; ii < 8; ii ++) {
                    if (v[i+dx[ii]][j+dy[ii]] == '@') {
                        cnt ++;
                    }
                }

                if (cnt < 4) {
                    ans ++;
                }
            }

        }
    }

    cout << ans << endl;

}

// correct ans: 1489