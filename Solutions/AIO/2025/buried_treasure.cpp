/*
    author:     ZH-170
    created_at: 2026-10-11 10:10:57
*/

#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;
    
int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, L;
    cin >> n >> L;

    int l = 1, r = L;
    for (int i = 0; i < n; i ++) {
        int xl, xr;
        cin >> xl >> xr;

        l = max(l, xl);
        r = min(r, xr);
    }

    if (l > r) {
        cout << 0 << endl;
    }
    else {
        cout << r-l+1 << endl;
    }
    
    return 0;
}

