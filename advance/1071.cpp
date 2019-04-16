#include <iostream>
#include <string>
#include <map>
using namespace std;
map <string, int> ma;
//map实现
int main() {
    char c;
    string tmp;
    int flag = true;
    map <string, int> :: iterator it;
    while((c = getchar())) {
        if((c >= '0' && c <= '9') || (c >= 'a' && c <='z') || (c >= 'A' && c <= 'Z')) {
            if(c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'a';
            } 
            tmp += c;
        } else {
            // cout << tmp << endl;
            if(tmp.size() || flag) {
                map <string, int> :: iterator it = ma.find(tmp);
                if(it == ma.end()) {
                    ma.insert(make_pair(tmp, 1));
                } else {
                    ma[tmp] ++;
                }
                tmp.clear();
            }
            flag = false;
        }
        if(c == '\n') {
            break;
        }
    }
    it = ma.begin();
    int maxn = 0;
    string res;
    while(it != ma.end()) {
        // cout << it->first << ' ' << it->second << endl;
        if(maxn < it->second) {
            maxn = it->second;
            res = it->first;
        }
        it++;
    }
    printf("%s %d\n", res.data(), maxn);
    
}