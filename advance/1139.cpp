#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef struct resinfo {
    int a;
    int b;
}resinfo;
int n, m;
typedef vector <int> node;
map <int, node> ma;

//注意号码为0的情况。。。。。。。
int cmp(resinfo a, resinfo b) {
    if(a.a != b.a) {
        return a.a < b.a;
    }
    return a.b < b.b;
}

void insert(int a, int b) {
    map <int, node> :: iterator it = ma.find(a);
    if(it == ma.end()) {
        node tmp;
        tmp.push_back(b);
        ma.insert(make_pair(a, tmp));
    } else {
        it->second.push_back(b);
    }
    it = ma.find(b);
    if(it == ma.end()) {
        node tmp;
        tmp.push_back(a);
        ma.insert(make_pair(b, tmp));
    } else {
        it->second.push_back(a);
    }
}

void getRes(int ta, int tb) {
    map <int, node> :: iterator it = ma.find(ta);
    if(it == ma.end()) {
        printf("0\n");
        return ;
    }
    it = ma.find(tb);
    if(it == ma.end()) {
        printf("0\n");
        return ;
    }
    node tmp = ma[ta];
    vector <resinfo> res;
    for(int i = 0; i < tmp.size(); ++i) {
        if(tmp[i]*ta > 0  && tmp[i] != tb) {
            int next1 = tmp[i];
            it = ma.find(next1);
            if(it == ma.end()) {
                continue;
            }
            node nextnode = it->second;
            for(int j = 0; j < nextnode.size(); ++j) {
                if(nextnode[j]*tb > 0   && nextnode[j] != ta ) {
                    int next2 = nextnode[j];
                    it = ma.find(next2);
                    if(it == ma.end()) {
                        continue;
                    }
                    node nextnode2 = it->second;
                    for(int k = 0; k < nextnode2.size(); ++k) {
                        if(nextnode2[k] == tb) {
                            next1 = next1 < 0 ? -next1 : next1;
                            next2 = next2 < 0 ? -next2 : next2;
                            next1 = next1 == 10000? 0 : next1;
                            next2 = next2 == 10000? 0 : next2;
                            resinfo restmp = {next1, next2};
                            res.push_back(restmp);
                            break;
                        }
                    }
                }
            }
        }
    }
    printf("%lu\n", res.size());
    sort(res.begin(), res.end(), cmp);
    for(int i = 0; i < res.size(); ++i) {
        printf("%04d %04d\n", res[i].a, res[i].b);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        int a, b;
        char buf1[128];
        char buf2[128];
        scanf("%s %s", buf1, buf2);
        if((a = atoi(buf1)) == 0) {
            a = buf1[0] == '-' ? -10000: 10000;
        }
        if((b = atoi(buf2)) == 0) {
            b = buf2[0] == '-' ? -10000: 10000;
        }
        insert(a, b);
    }
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; ++i) {
        int ta, tb;
        char buf1[128];
        char buf2[128];
        scanf("%s %s", buf1, buf2);
        if((ta = atoi(buf1)) == 0) {
            ta = buf1[0] == '-' ? -10000: 10000;
        }
        if((tb = atoi(buf2)) == 0) {
            tb = buf2[0] == '-' ? -10000: 10000;
        }
        
        getRes(ta, tb);
    }
}