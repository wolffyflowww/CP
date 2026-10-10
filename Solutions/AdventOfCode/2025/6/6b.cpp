// author: ZH-170
// created: 08 Dec 2025 01:03

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

    vector<string> v;
    for (int i = 0; i < n; i ++) {
        string s;
        getline(cin, s);

        v.pb(s);
    }

    string operation;
    getline(cin, operation);

    vector<pair<int, int>> v1;
    int pre = 0;
    for (int i = 1; i < operation.size(); i ++) {
        if (operation[i] == '+' || operation[i] == '*') {
            v1.pb({pre, i-2});
            pre = i;
        }
    }
    v1.pb({pre, operation.size()-1});

    lint ans = 0;
    for (int x = 0; x < v1.size(); x ++) {

        pair<int, int> r = v1[x];

        vector<int> num;
        for (int i = r.first; i <= r.second; i ++) {

            int temp = 0;
            for (int j = 0; j < n; j ++) {
                if (v[j][i] == ' ') {
                    temp += 0;
                }
                else {
                    temp += ( (int(v[j][i])-48) * pow(10, n-j-1) );
                }
            }
            
            while (temp%10 == 0) {
                temp /= 10;
            }

            num.pb(temp);
        }

        if (operation[r.first] == '+') {
            lint new_ans = 0;
            for (auto nn : num) {
                new_ans += nn;
            }
            ans += new_ans;
        }
        else if (operation[r.first] == '*') {
            lint new_ans = 1;
            for (auto nn : num) {
                new_ans *= nn;
            }
            ans += new_ans;
        }

    }

    cout << ans << endl;

}

// correct ans: 11052310600986