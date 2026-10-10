// author: ZH-170
// created: 01 Dec 2025 16:41

#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        string f; cin >> f; freopen(f.c_str(), "r", stdin); cout << endl;
    #endif

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int cur = 50, cnt = 0;
    int pre_sign = 1;
    int n = 4629;

    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;

        int f = 1;
        if (s[0] == 'L') {
            f = -1;
        }

        int num = 0;
        for (int i = 1; i < s.size(); i ++) {
            num += (int(s[i])-48)*pow(10, s.size()-i-1);
        }
        
        if (cur > 0 && f == 1) {
            cur += num;
            
            cnt += cur/100;
            cur %= 100;
        }
        else if (cur < 0 && f == -1) {
            cur += (f*num);

            cnt += abs(cur/100);
            cur %= 100;
        }
        else if (cur == 0) {
            cur += (f*num);
            
            cnt += abs(cur/100);
            cur %= 100;
        }
        else if (cur > 0 && f == -1) {
            if (num >= cur) {
                num -= cur;
                cur = 0;
                cnt ++;

                cur += (f*num);

                cnt += abs(cur/100);
                cur %= 100;
            }
            else {
                cur += (f*num);
            }
        }
        else if (cur < 0 && f == 1) {
            if (num >= abs(cur)) {
                num -= abs(cur);
                cur = 0;
                cnt ++;

                cur += (f*num);

                cnt += abs(cur/100);
                cur %= 100;
            }
            else {
                cur += (f*num);
            }
        }
        
    }

    cout << cnt; 
}

// correct ans: 6819

/*
cases:

1. cur: +, operation: +
do the operation then divides

2. cur: -, operation: -
do the operation then divides

3. cur: 0
do the operation then divides

4. cur: -, operation: +
try to make cur = 0 and then do case 3 (cur: 0)

5. cur: +, operation: -
try to make cur = 0 and then do case 3 (cur: 0)

*/