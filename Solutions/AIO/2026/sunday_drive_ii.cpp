/*
    author:     ZH-170
    created_at: 2026-10-10 16:32:29
*/
 
#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;
 
int main() {
 
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    vector<int> v;
    set<int> s;
 
    vector<vector<int>> val_i(1e4+1);
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        v.pb(x);
        s.insert(x);
 
        if (i > 0) val_i[x].pb(i);
    }
 
    vector<int> vs;
    for (auto i : s) vs.pb(i);
 
    vector<int> ans(n, -1);
    ans[0] = min(v[0], 1);
 
    for (int i = 1; i < n; i ++) {
        ans[i] = min(ans[i-1] + 1, v[i]);
    }
 
    for (int i = n-1; i >= 1; i --) {
 
        if (ans[i-1] - ans[i] > 1) {
            ans[i-1] = ans[i] + 1;
        }
    }
    
    int ans_sum = 0;
    for (auto i : ans) ans_sum += i;
 
    cout << ans_sum << endl;
 
    return 0;
}

