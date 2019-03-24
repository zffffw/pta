#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> L;

long long int n, m;
// string changeToTarget(long long int n, long long int base) {
//     if( n / base != 0) {
//         string t = changeToTarget(n/base, base);
//         int tmp = n % base;
//         string res = to_string(tmp);

//         return t + res;
//     } else {
//         int tmp = n % base;
//         string res = to_string(tmp);
//         return res;
//     }
// }

// bool judge(string s) {
//     string s_r = s;
//     reverse(s_r.begin(), s_r.end());
//     // cout << s_r << endl << s << endl;
//     return s_r == s;
//     // return true;
// }

int main() {
    cin >> n >> m;
    while(n) {
        // cout << "1" << endl;
        L.push_back(n % m);
        n /= m;
    }
    // int size = L.size() - 1;
    int flag = 1;
    for(int i = 0; i < L.size()/2; ++i) {
        if(L[i] != L[L.size() - 1 - i]) {
            flag = 0;
            break;
        }
    }
    if(flag) {
        cout << "Yes" << endl;
    } else  {
        cout << "No" << endl;
    }
    if(!L.size()) {
        cout << '0' << endl;
    } else {
        cout << L[L.size() - 1];
        for(int i = L.size() - 2; i >= 0; --i) {
            cout << ' ' << L[i];
        }
        cout << endl;
    }
    return 0;
}