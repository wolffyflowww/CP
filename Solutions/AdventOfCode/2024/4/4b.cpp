// author: ZH-170
// created: 01 Dec 2025 21:38

#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        string f; cin >> f; freopen(f.c_str(), "r", stdin); cout << endl;
    #endif

    ios::sync_with_stdio(false); cin.tie(nullptr);

    vector<string> v;
    int n = 140;
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        v.pb(s);
    }

    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    int ans = 0;
    for (int i = 1; i < n-1; i ++) {
        for (int j = 1; j < v[i].size()-1; j ++) {
            if (v[i][j] == 'A') {
                vector<int> check;
                for (int z = 1; z < 8; z += 2) {
                    int new_x = i + dx[z], new_y = j + dy[z];
                    check.pb(v[new_x][new_y]);
                }

                bool is_valid1 = false, is_valid2 = false;

                if (check[0] == 'M' && check[2] == 'S') {
                    is_valid1 = true;
                }
                if (check[0] == 'S' && check[2] == 'M') {
                    is_valid1 = true;
                }
                if (check[1] == 'M' && check[3] == 'S') {
                    is_valid2 = true;
                }
                if (check[1] == 'S' && check[3] == 'M') {
                    is_valid2 = true;
                }

                if (is_valid1 && is_valid2) {
                    ans ++;
                }
            }
        }
        
    }

    cout << ans << endl;
}


/*
8 1 2
7 x 3
6 5 4

*/


// correct ans: 1925