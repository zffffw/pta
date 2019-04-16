#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string n;
    cin >> n;
    int begin = 1;
    while(n != "6174" || begin) {
        begin = 0;
        while(n.size() < 4) {
            n.insert(0, 1, '0');
        }
        sort(n.begin(), n.end());
        string k = n.data();
        reverse(k.begin(), k.end());
        if(k == n) {
            printf("%s - %s = %04d\n", k.data(), n.data(), 0);
            break;
        }
        int tmp = atoi(k.data()) - atoi(n.data());
        printf("%s - %s = %04d\n", k.data(), n.data(), tmp);
        n = to_string(tmp);
    }
}