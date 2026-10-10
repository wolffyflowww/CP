/*
    author:     ZH-170
    created_at: 2026-10-10 16:57:24
*/
 
#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;
    
int main() {
 
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    lint n, k;
    cin >> n >> k;
 
    vector<lint> v;
    for (int i = 0; i < n; i ++) {
        lint x;
        cin >> x;
        v.pb(x);
    }
 
    int l;
    if (v.size() % 2 == 0) {
        l = (v.size()/2) - 1;
    }
    else {
        l = v.size()/2;
    }
 
    int r = l;
    while (r < n-1) {
        if (v[r+1] == v[l]) r++;
        else break;
    }
 
    lint added = 0;
    while (k - (r-l+1) >= 0) {
        
        lint max_next_step = 1e9;
        if (r != n-1) {
            max_next_step = v[r+1] - v[r];
        }
 
        lint number_of_decrement = min(max_next_step, k / (r-l+1));
 
        k -= ( (r-l+1) * number_of_decrement );
        added += number_of_decrement;
 
        while (r < n-1) {
            if (v[r+1] == (v[l] + added)) r++;
            else break;
        }
    }
 
    cout << v[l] + added << endl;
 
    return 0;
}
