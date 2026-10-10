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
    
    vector<vector<int>> neighbour_cnt;
    
    first_row = '.' + first_row + '.';

    string empty_row = "";
    vector<int> empty_neighbour;
    
    for (auto i : first_row) {
        empty_row += '.';
        empty_neighbour.pb(0);
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

    neighbour_cnt.pb(empty_neighbour);
    queue<pair<int, int>> q;
    
    for (int i = 1; i <= n; i ++) {
        vector<int> neighbours = {0};
        for (int j = 1; j < first_row.size()-1; j ++) {

            if (v[i][j] == '@') {
                
                int cnt = 0;
                for (int ii = 0; ii < 8; ii ++) {
                    if (v[i+dx[ii]][j+dy[ii]] == '@') {
                        cnt ++;
                    }
                }

                if (cnt < 4) {
                    q.push({i, j});
                }

                neighbours.pb(cnt);

            }
            else neighbours.pb(0);

        }
        neighbours.pb(0);
        neighbour_cnt.pb(neighbours);
    }
    neighbour_cnt.pb(empty_neighbour);

    while (!q.empty()) {
        pair<int, int> pos = q.front();
        q.pop();

        if (v[pos.first][pos.second] == '@') {
            v[pos.first][pos.second] = '.';
            ans ++;

            for (int i = 0; i < 8; i ++) {
                int new_x = pos.first + dx[i], new_y = pos.second + dy[i];

                neighbour_cnt[new_x][new_y] --;
                if (neighbour_cnt[new_x][new_y] < 4) {
                    q.push({new_x, new_y});
                }

            }
        
        }
        
    }

    cout << ans << endl;

}

// correct ans: 8890