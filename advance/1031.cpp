#include <iostream>
#include <string>

using namespace std;

string s;

int main() {
    cin >> s;
    int N = s.length();
    int n1, n2;
    int best1 = 0, best2;
    for(n2 = 3; n2 <= N; ++n2) {
        int tmp = N + 2 - n2;
        if(tmp % 2 == 0) {
            n1 = tmp/2;
            // cout << n1 << endl;
            if (n1 <= n2) {
                if(best1 < n1) {
                    best1 = n1;
                    best2 = n2;
                }
            }
        }
    }
    // cout << N << ' ' << best1 << ' ' << best2 << endl;
    int st = 0;
    int en = N - 1;
    for(int i = 0; i < best1 - 1; ++i) {
        cout << s[st];
        for(int j = 0; j < best2 - 2; ++j) {
            cout << ' ';
        }
        cout << s[en];
        st++;
        en--;
        cout << endl;
    }
    int tmp = best1 - 1;
    for(int i = 0; i < best2; ++i) {
        cout << s[tmp];
        tmp++;
    }
    cout << endl;

    
}