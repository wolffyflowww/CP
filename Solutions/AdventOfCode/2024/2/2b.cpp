// author: ZH-170
// created: 02 Dec 2025 17:24

#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;

bool check (vector<int> v) {
    bool is_valid = true;
    int increasing = (v[1] > v[0]) ? 1 : -1;

    if (abs(v[1] - v[0]) > 3 || v[1] == v[0]) {
        is_valid = false;
    }
    else {

        for (int i = 2; i < v.size(); i ++) {
            int cur;
            if (v[i] == v[i-1]) {
                is_valid = false;
                break;
            }
            if (v[i] > v[i-1]) cur = 1;
            if (v[i] < v[i-1]) cur = -1;

            if (cur != increasing) {
                is_valid = false;
                break;
            }

            if (abs(v[i]-v[i-1]) > 3) {
                is_valid = false;
                break;
            }
        }
    }

    return is_valid;
}

int main() {
    #ifndef ONLINE_JUDGE
        string f; cin >> f; freopen(f.c_str(), "r", stdin); cout << endl;
    #endif

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n = 1000;
    int ans = 0;

    for (int i = 0; i < n; i ++) {
        string s;
        getline(cin, s);
        
        s += ' ';

        vector<int> v;
        string temp_s = "";
        for (int i = 0; i < s.size(); i ++) {
            
            if (s[i] == ' ') {
                
                int a = 0;
                for (int j = 0; j < temp_s.size(); j ++) {
                    a += (int(temp_s[j])-48)*pow(10, temp_s.size()-j-1);
                }

                v.pb(a);
                temp_s = "";
            }
            else {
                temp_s += s[i];
            }
        }


        if (check(v)) {
            ans ++;
        }
        else {
            bool is_valid = false;
            for (int i = 0; i < v.size(); i ++) {
                vector<int> vv;
                for (int j = 0; j < v.size(); j ++) {
                    if (j == i) continue;

                    vv.pb(v[j]);
                }

                if (check(vv)) {
                    is_valid = true;
                    break;
                }
                
                if (is_valid) break;
            }

            if (is_valid) ans ++;
        }

    }

    cout << ans << endl;
}

// correct ans: 381