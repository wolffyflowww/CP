// author: ZH-170
// created: 07 Dec 2025 21:04

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
    n = 4;

    vector<vector<int>> v(n);
    for (int i = 0; i < n; i ++) {
        string s;
        getline(cin, s);

        string cur = "";
        for (int ii = 0; ii < s.size(); ii ++) {
            if (s[ii] == ' ') {
                if (cur != "") {
                    int temp = 0;
                    for (int z = 0; z < cur.size(); z ++) {
                        temp += ((int(cur[z])-48) * pow(10, cur.size()-1-z));
                    }
                    
                    v[i].pb(temp);
                }
                cur = "";
            }
            else {
                cur += s[ii];
            }
        }

        if (cur != "") {
            int temp = 0;
            for (int z = 0; z < cur.size(); z ++) {
                temp += ((int(cur[z])-48) * pow(10, cur.size()-1-z));
            }
            
            v[i].pb(temp);
        }
    }
    
    vector<int> operation;
    // +: 1, *: 2

    for (int i = 0; i < v[0].size(); i ++) {
        char c;
        cin >> c;

        if (c == '+') {
            operation.pb(1);
        }
        else {
            operation.pb(2);
        }
    }

    lint ans = 0;
    for (int i = 0; i < v[0].size(); i ++) {
        if (operation[i] == 1) {
            lint temp = 0;
            for (int ii = 0; ii < n; ii ++) {
                temp += v[ii][i];
            }
            ans += temp;
        }
        if (operation[i] == 2) {
            lint temp = 1;
            for (int ii = 0; ii < n; ii ++) {
                temp *= v[ii][i];
            }
            ans += temp;
        }
    }

    cout << ans << endl;
}


// correct ans: 6605396225322