#include<bits/stdc++.h>
#define lint long long int
#define pb push_back
using namespace std;


string to_bin(int x, int s){
    string ans;
    for(int i = 0; i < s; i ++){
        ans += '0';
    }

    for(int i = s-1; i >= 0; i --){
        if(x%3==1){
            ans[i] = '1';
        }
        else if(x%3==2){
            ans[i] = '2';
        }
        else ans[i] = '0';

        x/=3;
    }
    return ans;
}

vector<pair<lint, int>> v;

// bool generator1(string temp, string ttl, ){
    
//     if(s[i] != ':' && s[i] != ' '){
//         lint temp = int(s[i])-48;
//         cur*=10;
//         cur+=temp;
//     }
//     else if(s[i] == ':'){
//         ttl = cur;
//         cur = 0;
//     }
//     else if(s[i] == ' ' && s[i-1] != ':'){
//         v.pb(cur);
//         cur = 0;
//     }
// }

bool generator2(string temp, lint ttl){

    lint temp1 = v[0].first;
    lint pre_num = v[0].first;
    char pre_type = '3';
    // cout << temp1 << " " << pre_num << " " << pre_type << endl;

    for(int j = 1; j <= temp.size(); j ++){
        // cout << temp1 << " " << pre_num << " " << pre_type << endl;
        if(temp1 > ttl){break;}
        if(pre_num > ttl){break;}
        if(temp[j-1] == '0'){
            temp1 += v[j].first;
        }
        else if(temp[j-1] == '1'){
            temp1 *= v[j].first;
        }
        else if(temp[j-1] == '2'){
            temp1*=(pow(10, v[j].second));
            temp1 += v[j].first;
        }
        // if(temp[j-1] == '0' || temp[j-1] == '1'){ // 0=>+, 1=>*
        //     if(pre_type == '0'){
        //         temp1 += pre_num;
        //     }
        //     else if(pre_type == '1'){
        //         temp1 *= pre_num;
        //     }
        //     else if(pre_type == '3'){
        //         temp1 = pre_num;
        //     }

        //     pre_type = temp[j-1];
        //     pre_num = v[j].first;
        // }

    //     else if(temp[j-1] == '2'){ // 2=>||
    //         for(int i = 0; i < v[j].second; i ++){
    //             pre_num *= 10;
    //         }
    //         pre_num += v[j].first;
    //     }
        
    }

    // if(pre_type == '0'){
    //     temp1 += pre_num;
    // }
    // else if(pre_type == '1'){
    //     temp1 *= pre_num;
    // }
    // else if(pre_type == '3'){
    //     temp1 = pre_num;
    // }

    // cout << temp1 << " " << pre_num << " " << pre_type << endl;


    return (temp1 == ttl);
}

int main() {
    // v = {
    //     {2, 1}, 
    //     {3, 1}, 
    //     {20, 2}, 
    //     {123, 3}
    // };
    // cout << generator2("020", 1e9);
    // return 0;
    int n = 50;
    lint ans = 0;
	// lint max_v = 0;
	// lint m = 0;
    while(n--){
        string s;
        getline(cin, s);
        lint ttl;

        lint cur = 0;
        lint cur_i = 0;

        for(int i = 0; i < s.size(); i ++){
            if(s[i] != ':' && s[i] != ' '){
                lint temp = int(s[i])-48;
                cur*=10;
                cur+=temp;
                cur_i ++;
            }
            else if(s[i] == ':'){
                ttl = cur;
                cur = 0;
                cur_i = 0;
            }
            else if(s[i] == ' ' && s[i-1] != ':'){
                v.pb({cur, cur_i});
                cur = 0;
                cur_i = 0;
            }
        }
        v.pb({cur, cur_i});
        
        // cout << "ttl: " << ttl << endl;
        // for(auto i : v){cout << i.first << " ";} cout << endl << endl;

        
        // max_v = max(max_v, (lint)v.size());
        // m = max(m, ttl);

        int cnt = v.size()-1;
        bool check = false;
        for(int i = 0; i < pow(3, cnt); i ++){
            string temp = to_bin(i, cnt);
            // cout << temp << endl;
            bool checker = false;
            for(int j = 1; j <= temp.size(); j ++){
                
                if(generator2(temp, ttl)){
                    checker = true;
                    break;
                }
            }
            // cout << temp1 << endl << endl;
            if(checker){
                check = true;
                // cout << ttl << endl;
                break;
            }
        }

        if(check){ans+=ttl;}

        // for(auto i : v){
            // cout << i.first << " " << i.second << endl;
        // }
        // cout << endl;

        v.clear();

    }

    cout << ans << endl;

    // cout << to_bin(10, 10);

    // cout << max_v << endl << m << endl;
    // string s = "123";
    // cout << int(s[0]) << " " << int(s[1]) << " " << int(s[2]) << endl;
    // 49 50 51
}

// cur_type = 1, 2
// cur_num
// temp1

// if temp[j-1] == '0' => +
// temp1 += 

// if temp[j-1] == '1' => *


// if temp[j-1] == '2'
// cur_num || v[j]
