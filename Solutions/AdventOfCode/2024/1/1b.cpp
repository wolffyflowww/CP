// author: ZH-170
// created: 02 Dec 2025 17:17

#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        string f; cin >> f; freopen(f.c_str(), "r", stdin); cout << endl;
    #endif

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n = 1000;

    vector<int> v1, v2(1e5, 0);
    for (int i = 0; i < n; i ++) {
        int a, b;
        cin >> a >> b;

        v1.pb(a);
        v2[b] ++;
    }

    lint sum = 0;
    for (int i = 0; i < n; i ++) {
        sum += (v1[i]*v2[v1[i]]);
    }

    cout << sum << endl;
}

// correct ans: 19457120