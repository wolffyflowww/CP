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

    lint ans = 0;
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

    // merge
    vector<pair<lint, lint>> new_r;
    lint cur_f = r[0].first, cur_s = r[0].second;

    for (int i = 1; i < r.size(); i ++) {
        if (r[i].first <= cur_s) {
            cur_s = max(cur_s, r[i].second);
        }
        else {
            ans += (cur_s - cur_f + 1);

            cur_f = r[i].first;
            cur_s = r[i].second;
        }
    }

    ans += (cur_s - cur_f + 1);

    cout << ans << endl;

}

// correct ans: 353507173555373