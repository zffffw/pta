#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
string tmp;
bool judge() {
    int last = 0;
    int flag1 [10] = {0};
    int flag2 [10] = {0};
    for(int i = s.size() - 1; i >= 0; --i) {
        int t = (s[i] - '0')*2 + last;
        tmp += (t % 10) + '0';
        last = t / 10;
        flag1[s[i] - '0'] += 1;
        flag2[t % 10] += 1;
    }
    if (last == 1) {
        tmp += '1';
        return false;
    }
    for(int i = 0; i <10; ++i) {
        if(flag1[i] != flag2[i]) {
            return false;
        }
    }
    return true;
}
int main() {
    cin >> s;
    cout << (judge() ? "Yes" : "No") << endl;
    reverse(tmp.begin(), tmp.end());
    cout << tmp << endl;
}