// author: ZH-170
// created: 02 Dec 2025 17:58

#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;

bool check_int(char c) {
    if (int(c) >= int('0') && int(c) <= int('9')) return true;
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
        string f; cin >> f; freopen(f.c_str(), "r", stdin); cout << endl;
    #endif

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n = 6;
    lint ans = 0;

    bool doit = true;

    while(n--) {
        string s;
        getline(cin, s);

        for (int i = 0; i < s.size()-7; i ++) {
            if (s.substr(i, 4) == "do()") {
                doit = true;
            }
            else if (s.substr(i, 7) == "don't()") {
                doit = false;
            }
            else if (s.substr(i, 4) == "mul(" && doit) {
                int close_bracket = -1;
                for (int j = i+4; j < min((int)s.size(), i+4+8); j ++) {
                    if (s[j] == ')') {
                        close_bracket = j;
                    }
                }

                if (close_bracket == -1) {
                    continue;
                }
                string k = s.substr(i+4, close_bracket - (i+4));

                string a = "", b = "";
                bool is_valid = true;
                int put_a = 1;
                
                for (auto c : k) {
                    if (c == ',') {
                        put_a ++;
                        if (put_a > 2) {
                            is_valid = false;
                            break;
                        }
                    }
                    else {
                        if (!check_int(c)) {
                            is_valid = false;
                            break;
                        }

                        if (put_a == 1) {
                            a += c;
                        }
                        else if (put_a == 2) {
                            b += c;
                        }
                        else {
                            is_valid = false;
                            break;
                        }
                    }
                }

                int a1 = 0, b1 = 0;
                for (int d = 0; d < a.size(); d ++) {
                    a1 += (int(a[d])-48) * pow(10, a.size() - 1 - d);
                }
                for (int d = 0; d < b.size(); d ++) {
                    b1 += (int(b[d])-48) * pow(10, b.size() - 1 - d);
                }

                ans += (lint)(a1*b1);

            }
        }
    }

    cout << ans << endl;
}

// correct ans: 87163705