#include <iostream>
#include <map>
using namespace std;

map <char, int> ma;
int main() {
    char c;
    int storeCnt = 0;
    while((c = getchar()) != '\n') {
        map <char, int> :: iterator it = ma.find(c);
        if(it == ma.end()) {
            ma.insert(make_pair(c, 1));
        } else {
            it->second ++;
        }
        storeCnt ++;
    }
    int cnt = 0;
    int notfind = 0;
    int need[256] = {0};
    while((c = getchar()) != '\n') {
        need[c]++;
        cnt ++;
    }
    for(int i = 0; i < 256; ++i) {
        int total = need[i];
        if(total) {
            if(ma[i] < total) {
                notfind += total - ma[i];
            }
        }
    }
    if(notfind) {
        printf("No %d\n", notfind);
    } else {
        printf("Yes %d\n", storeCnt - cnt);
    }
}