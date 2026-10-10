/*
    author:     ZH-170
    created_at: 2026-10-10 15:44:52
*/
 
#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;
    
int main() {
 
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    int MAX = 0;
    int cur;
    cin >> cur;
 
    for (int i = 0; i < n-1; i ++) {
        int x;
        cin >> x;
        MAX = max(MAX, x-cur);
        cur = x;
    }
 
    cout << MAX << endl;
 
    return 0;
}
