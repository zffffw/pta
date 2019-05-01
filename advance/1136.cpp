#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a;

string add_(string a, string b) {
    while(a.length() < b.length()) {
        a.insert(0, 1, '0');
    }
    while(b.length() < a.length()) {
        b.insert(0, 1, '0');
    }
    int last = 0;
    string res;
    for(int i = a.length() - 1; i >= 0; i --) {
        // cout << res << endl;
        res += (a[i] + b[i] + last - 2*'0') % 10 + '0';
        last = (a[i] + b[i] + last - 2*'0') / 10;
    }
    reverse(res.begin(), res.end());
    if(last)
        res.insert(0, 1, '1');
    return res;
}

int main() {
    cin >> a;
    string b;
    b = a;
    int i = 0;
    bool find = false;
    while(i < 10) {
        reverse(b.begin(), b.end());
        if(a == b) {
            find = true;
            break;
        }
        
        string tmp = add_(a, b);
        printf("%s + %s = %s\n", a.data(), b.data(), tmp.data());
        a = b = tmp;
        i++;
    }
    if(find)
        printf("%s is a palindromic number.\n", a.data());
    else 
        printf("Not found in 10 iterations.\n");
}