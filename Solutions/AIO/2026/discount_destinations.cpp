/*
    author:     ZH-170
    created_at: 2026-10-10 15:56:06
*/
 
#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;
    
int main() {
 
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    int n, k, d;
    cin >> n >> k >> d;
 
    vector<int> v;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        v.pb(x);
    }
 
    lint ans = 0;
    int l = 0, r = 0, pre_sum = 0;
 
    vector<int> charged;
 
    while (r < n) {
        if (r - l + 1 > k) {
            pre_sum -= charged[l];
            l ++;
        }
 
        int increment = min(d-pre_sum, v[r]);
        charged.pb(increment);
        ans += increment;
        pre_sum += increment;
 
        r++;
    }
 
    cout << ans << endl;
 
    
    return 0;
}

