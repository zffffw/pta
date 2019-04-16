#include <iostream>
#include <map>
using namespace std;

map <long int, int> ma;
int m, n;

int main() {
    scanf("%d %d", &n, &m);
    int cnt = 0;
    long int res ;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            int tmp;
            scanf("%d", &tmp);
            map <long int, int> :: iterator it = ma.find(tmp);
            if(it == ma.end()) {
                ma.insert(make_pair(tmp, 1));
                it = ma.find(tmp);
            } else {
                it->second++;
            }
            if(cnt < it->second) {
                cnt = it->second;
                res = it->first;
            }
        }
    }
    printf("%ld\n", res);
}