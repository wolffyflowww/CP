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

    queue<pair<pair<int, int>, pair<int, int>>> q;
    // ((x, y), (letter, directions))

    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < v[i].size(); j ++) {
            if (v[i][j] == 'X') {
                for (int z = 0; z < 8; z ++) {
                    int new_x = i + dx[z], new_y = j + dy[z];
                    if (new_x < 0 || new_x >= n) {
                        continue;
                    }
                    if (new_y < 0 || new_y >= v[0].size()) {
                        continue;
                    }
                    if (v[new_x][new_y] == 'M') {
                        q.push({ {new_x, new_y} , {1, z+1} });
                    }
                }
            }
        }
        
    }

    string target = "XMAS";
    
    int ans = 0;
    while (!q.empty()) {
        pair<int, int> xy = q.front().first;
        int letter = q.front().second.first;
        int d = q.front().second.second;
        q.pop();

        if (letter == 3) {ans ++; continue;}
        

        int new_x = xy.first + dx[d-1], new_y = xy.second + dy[d-1];
        if (new_x < 0 || new_x >= n) {
            continue;
        }
        if (new_y < 0 || new_y >= v[0].size()) {
            continue;
        }

        if (v[new_x][new_y] == target[letter+1]) {
            q.push({ {new_x, new_y} , {letter + 1, d} });
        }
            
    }
    
    cout << ans << endl;
}


/*
8 1 2
7 x 3
6 5 4

*/


// correct ans: 2483