#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef struct node {
    string name;
    int gp;
    int gm;
    int gf;
    int gt;
    bool operator < (const node &A) const {
        if(gt != A.gt)
            return gt > A.gt;
        else
            return name < A.name;
    }
} node;

map <string, node> ma;
int p, m, n;

int main() {
    map <string, node> :: iterator it;
    scanf("%d %d %d", &p, &m, &n);
    for(int i = 0; i < p; ++i) {
        char buf[128];
        int a;
        scanf("%s %d", buf, &a);
        string name = buf;
        it = ma.find(name);
        if(it == ma.end()) {
            node tmp = {name, a, -1, -1, -1};
            ma.insert(make_pair(name, tmp));
        }
    }
    for(int i = 0; i < m; ++i) {
        char buf[128];
        int a;
        scanf("%s %d", buf, &a);
        string name = buf;
        it = ma.find(name);
        if(it == ma.end()) {
            node tmp = {name, -1, a, -1, -1};
            ma.insert(make_pair(name, tmp));
        } else {
            it->second.gm = a;
        }
    }
    for(int i = 0; i < n; ++i) {
        char buf[128];
        int a;
        scanf("%s %d", buf, &a);
        string name = buf;
        it = ma.find(name);
        if(it == ma.end()) {
            node tmp = {name, -1, -1, a, -1};
            ma.insert(make_pair(name, tmp));
        } else {
            it->second.gf = a;
        }
    }
    it = ma.begin();
    vector <node> res;
    while(it != ma.end()) {
        if(it->second.gp >= 200) {
            if(it->second.gm > it->second.gf)
                it->second.gt = (0.4*(float)(it->second.gm) + 0.6*(float)(it->second.gf) + 0.5);
            else
                it->second.gt = it->second.gf;
            if(it->second.gt >= 60)
                res.push_back(it->second);
        }
        it++;
    }
    sort(res.begin(), res.end());
    for(int i = 0; i < res.size(); ++i) {
        printf("%s %d %d %d %d\n", res[i].name.data(), res[i].gp, res[i].gm, res[i].gf, res[i].gt);
    }


}