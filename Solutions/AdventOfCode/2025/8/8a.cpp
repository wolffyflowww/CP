// author: ZH-170
// created: 09 Dec 2025 01:26

#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;

lint cal_dis(tuple<lint, lint, lint> a, tuple<lint, lint, lint> b) {
    lint de1 = (lint)((get<0>(a) - get<0>(b)) * (get<0>(a) - get<0>(b)));
    lint de2 = (lint)((get<1>(a) - get<1>(b)) * (get<1>(a) - get<1>(b)));
    lint de3 = (lint)((get<2>(a) - get<2>(b)) * (get<2>(a) - get<2>(b)));

    
    return (de1 + de2 + de3);
}

vector<int> parent(1000);
int highest_parent(int x) {
    if (parent[x] != x) {
        parent[x] = highest_parent(parent[x]);
    }
    return parent[x];
}

int main() {
    #ifndef ONLINE_JUDGE
        string f; cin >> f; freopen(f.c_str(), "r", stdin); cout << endl;
    #endif

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    n = 1000;

    vector<tuple<lint, lint, lint>> v;
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;

        vector<string> vs;
        string cur = "";
        for (int ii = 0; ii < s.size(); ii ++) {
            if (s[ii] == ',') {
                vs.pb(cur);
                cur = "";
            }
            else {cur += s[ii];}
        }
        vs.pb(cur);

        vector<int> vi;
        int cur_n = 0;
        for (auto str : vs) {
            for (int ii = 0; ii < str.size(); ii ++) {
                cur_n += ( (int(str[ii])-48) * pow(10, str.size()-ii-1) );
            }
            vi.pb(cur_n);
            cur_n = 0;
        }

        v.pb(make_tuple(vi[0], vi[1], vi[2]));
    }

    vector<pair<lint, pair<int, int>>> vv;

    for (int i = 0; i < v.size()-1; i ++) {
        for (int j = i+1; j < v.size(); j ++) {
            lint dis = cal_dis(v[i], v[j]);
            vv.pb({dis, {i, j}});
        }
    }

    sort(vv.begin(), vv.end());

    iota(parent.begin(), parent.end(), 0);

    for (int i = 0; i < 1000; i ++) {
        int v1 = vv[i].second.first, v2 = vv[i].second.second;
        
        parent[highest_parent(v2)] = highest_parent(v1);
    }

    vector<int> ans(n, 0);
    for (int i = 0; i < n; i ++) {
        ans[highest_parent(i)] ++;
    }
    
    sort(ans.begin(), ans.end(), greater<int>());
    
    cout << (lint)(ans[0] * ans[1] * ans[2]) << endl;
    
}

// correct ans: 96672