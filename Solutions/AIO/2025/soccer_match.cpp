/*
    author:     ZH-170
    created_at: 2026-10-11 10:04:48
*/

#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;
    
int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    int score_1 = 0, score_2 = 0;
    bool ans = false;

    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;

        if (x == 1) {
            score_1 ++;
        }
        else {
            score_2 ++;
        }

        if (score_1 > score_2) {
            ans = true;
        }
    }

    if (ans) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    
    return 0;
}

