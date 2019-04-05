#include <iostream>
#include <algorithm>
using namespace std;


string add(string a, string b ) {
    int d = 0;
    int last = 0;
    string res;
    for(int i = a.size() - 1; i >= 0; --i) {
        char c = ( last + a[i] - '0' + b[i] - '0') % 10 + '0';
        last = ( last + a[i] - '0' + b[i] - '0') / 10;
        res.insert(0, 1, c);
    }
    if(last) {
        res.insert(0, 1, '1');
    }
    return res;
}

int main() {
    string s;
    int K, i;
    cin >> s >> K;
    for(i = 0; i < K; ++i) {
        string t = s.data();
        reverse(t.begin(), t.end());
        if(s == t) {
            break;
        }
        s = add(s, t);
    }
    cout << s << endl << i << endl;
}