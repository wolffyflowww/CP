/*
    author:     ZH-170
    created_at: 2026-10-10 15:48:26
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
    int MIN = 1e9 + 1;
    int min_index = -1;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        v.pb(x);
 
        if (x < MIN) {
            MIN = x;
            min_index = i;
        }
    }
 
    bool ans = true;
 
    int pre_index = min_index, cur_index = min_index + 1;
 
    for (int i = 0; i < n-1; i ++) {
        
        if (cur_index == n) cur_index = 0;
 
        if (v[cur_index] < v[pre_index]) {
            ans = false;
            break;
        }
 
        pre_index = cur_index;
        cur_index ++;
 
    }
 
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}
