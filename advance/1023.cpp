#include <iostream>
#include <string>
using namespace std;


string s;
string tmp = "0000000000000000000000";
int digits;
bool judge() {
    
    int k = 0;
    int last = 0;
    for(int i = s.size() - 1; i >= 0; --i) {
        int t = s[i] - '0';
        t *= 2;
        if (t +  last > 9) {
            tmp[i] = (t +  last) % 10 + '0';
            last = 1;
        } else {
            tmp[i] = (t +  last) + '0';
            last = 0;
        }
    }
    if (last == 1) {
        tmp.insert(0, 1, '1');
        digits += 1;
        return false;
    }
    int flag1 [10] = {0};
    int flag2 [10] = {0};
    for(int i = 0; i < s.size(); ++i) {
        flag1[s[i] - '0'] += 1;
        flag2[tmp[i] - '0'] += 1;
    }
    int flag = 1;
    for(int i = 0; i <10; ++i) {
        if(flag1[i] != flag2[i]) {
            flag = 0;
            break;
        }
    }
    
    // cout << tmp.substr(0, s.size()) << endl;
    return flag;
}

int main() {
    cin >> s;
    digits = s.size();
    // for(int i = 0; i < 1000000; ++i) {
        // s.clear();
        // tmp = "0000000000000000000000";
        // s = to_string(i);
        if(judge()) {
            cout << "Yes" << endl;
            // cout << s << endl;
            
        } else {
            cout << "No" << endl;
        }
    // }
    cout << tmp.substr(0, digits);
}