#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string tmp;
string res;
int main() {
    int a, b;
    cin >> a >> b;
    int r = a+b;
    tmp = r > 0 ? to_string(r):to_string(-(r));
    int count = 0;
    for(int i = tmp.size(); i >= 0; --i) {
        res.push_back(tmp[i]);
        if(i == 0) {
            break;
        }
        if( count % 3 == 0 && count) {
            count = 0;
            res.push_back(',');
        }
        count ++;
    }
    reverse(res.begin(), res.end());
    if(r >= 0) {
        cout << res << endl;
    } else {
        cout << '-' << res << endl;
    }
    return 0;
}