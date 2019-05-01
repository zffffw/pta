#include <iostream>
#include <map>
#include <vector>
using namespace std;

map <int, int> ma[51];
vector <int> v[51];
int n, k;

int main() {
    scanf("%d", &n);
    map <int, int> :: iterator it;
    int m;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &m);
        for(int j = 0; j < m; ++j) {
            int tmp;
            scanf("%d", &tmp);
            // v[i].push_back(tmp);
            it = ma[i].find(tmp);
            if(it == ma[i].end()) {
                ma[i].insert(make_pair(tmp, 1));
            }
        }
    }
    scanf("%d", &k);
    map <int, int> :: iterator ita, itb;
    for(int i = 0; i < k; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        float countCom = 0;
        float countNot = 0;
        ita = ma[a].begin();
        itb = ma[b].begin();
        while(ita != ma[a].end() && itb != ma[b].end()) {
            if(ita->first < itb->first) {
                ita ++;
            } else if(ita->first > itb->first) {
                itb ++;
            } else {
                countCom ++;
                ita ++;
                itb ++;
            }
            countNot ++;
        }
        while(ita != ma[a].end()) {
            ita ++;
            countNot ++;
        }
        while(itb != ma[b].end()) {
            itb ++;
            countNot ++;
        }
        printf("%.1f%%\n", countCom * 100.0 / countNot);
    }
}