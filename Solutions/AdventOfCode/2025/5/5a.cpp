// author: ZH-170
// created: 07 Dec 2025 08:49

#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        string f; cin >> f; freopen(f.c_str(), "r", stdin); cout << endl;
    #endif

    ios::sync_with_stdio(false); cin.tie(nullptr);

    string s;
    getline(cin, s);

    vector<pair<lint, lint>> r;
    while (!s.empty()) {
        string a_s = "", b_s = "";
        lint a = 0, b = 0;
        int i_stop = -1;

        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '-') {
                i_stop = i;
                break;
            }
            a_s += s[i];
        }
        for (int i = i_stop+1; i < s.size(); i ++) {
            b_s += s[i];
        }

        for (int i = 0; i < a_s.size(); i ++) {
            a += (lint)((int(a_s[i])-48) * pow(10, a_s.size()-i-1));
        }
        for (int i = 0; i < b_s.size(); i ++) {
            b += (lint)((int(b_s[i])-48) * pow(10, b_s.size()-i-1));
        }

        r.pb({a, b});

        getline(cin, s);
    }

    sort(r.begin(), r.end(), [](pair<lint, lint> a, pair<lint, lint> b){
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });

    getline(cin, s);

    vector<lint> v;
    string pre_s;
    
    while (s != pre_s) {
        lint x = 0;

        for (int i = 0; i < s.size(); i ++) {
            x += (lint)((int(s[i])-48) * pow(10, s.size()-1-i));
        }
        v.pb(x);

        pre_s = s;
        getline(cin, s);
    }

    sort(v.begin(), v.end());

    int ri = 0;
    int ans = 0;
    for (int i = 0; i < v.size(); i ++) {
        if (ri == r.size()) {
            break;
        }
        if (v[i] < r[ri].first) {
            continue;
        }
        else {
            if (v[i] > r[ri].second) {
                i --;
                ri ++;
            }
            else {
                ans ++;
            }
        }
    }

    cout << ans << endl;

}


// correct ans: 623