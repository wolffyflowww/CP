// author: ZH-170
// created: 02 Dec 2025 16:10

#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        string f; cin >> f; freopen(f.c_str(), "r", stdin); cout << endl;
    #endif

    ios::sync_with_stdio(false); cin.tie(nullptr);

    string s;
    cin >> s;
    
    // make the last one can be add into the list
    s += ',';

    vector<pair<lint, lint>> v;
    string a = "", b = "";
    bool is_first = true;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == '-') {
            is_first = false;
        }
        else if (s[i] == ',') {
            lint a1 = 0;
            for (int j = 0; j < a.size(); j ++) {
                a1 += (int(a[j]) - 48) * pow(10, (a.size() - j - 1));
            }

            lint b1 = 0;
            for (int j = 0; j < b.size(); j ++) {
                b1 += (int(b[j]) - 48) * pow(10, (b.size() - j - 1));
            }

            v.pb({a1, b1});
            a = ""; b = ""; is_first = true;
        }
        else {
            if (is_first) {
                a += s[i];
            }
            else {
                b += s[i];
            }
        }
    }

    lint sum = 0;
    vector<lint> invalid_id;
    for (auto i : v) {

        for (lint x = i.first; x <= i.second; x ++) {

            lint temp_x = x;
            int dig = 0;
            while (temp_x != 0) {
                temp_x /= 10;
                dig ++;
            }

            for (int i = dig-1; i >= 1; i --) {
                if (dig % i != 0) {
                    continue;
                }

                lint modulo = 0;
                for (int ii = dig-i; ii >= 0; ii -= i) {
                    modulo += pow(10, ii);
                }
                                                                                                                                                                                                                                                                                                             
                if (x % modulo == 0) {
                    sum += x;
                    cout << x << endl;
                    break;
                }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
            }

            
        }
        
    }

    cout << sum << endl;

}

// correct ans: 46769308485