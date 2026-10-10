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

    vector<int> v1, v2;
    for (int i = 0; i < n; i ++) {
        int a, b;
        cin >> a >> b;

        v1.pb(a); v2.pb(b);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    lint sum = 0;
    for (int i = 0; i < n; i ++) {
        sum += abs(v1[i] - v2[i]);
    }

    cout << sum << endl;
}

// correct ans: 2264607