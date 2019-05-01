
#include <iostream>
#include <string>
using namespace std;

string s;
int main() {
    cin >> s;
    int P[100001];
    int T[100001];
    int cnt = 0;
    int cntP = 0;
    for(string :: iterator it = s.begin(); it != s.end(); ++it) {
        // cout << *it;
        switch (*it) {
            case 'P':
                cntP++;
            break;
            case 'A':
                P[cnt++] = cntP;
            break;
        }
    }
    // cout << endl;
    // cout << cnt << endl;
    int cntA = cnt;
    int cntT = 0;
    for(int i = s.size() - 1; i >= 0; --i) {
        // cout << s[i];
        switch (s[i]) {
            case 'T':
                cntT++;
            break;
            case 'A':
                T[--cnt] = cntT;
            break;
        }
    }
    // cout << endl;
    // for(int i = 0; i < cntA; ++i) {
    //     cout << P[i] << ' ';
    // }
    // cout << endl;
    // for(int i = 0; i < cntA; ++i) {
    //     cout << T[i] << ' ';
    // }
    // cout << endl;
    long long res;
    for(int i = 0; i < cntA; ++i) {
        long long tmp = P[i]*T[i] % 1000000007;
        res = (res + tmp) % 1000000007;
    }
    cout << res << endl;

}