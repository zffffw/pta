#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef struct node {
    string name;
    int age;
    int netWorth;
} node;
vector <node> v;
int n, m;

int cmp(node a, node b) {
    if(a.netWorth != b.netWorth) {
        return a.netWorth > b.netWorth;
    } else if(a.age != b.age){
        return a.age < b.age;
    } else if (a.name != b.name) {
        return a.name < b.name;
    } else {
        return false;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        char buf[128];
        int a, w;
        scanf("%s %d %d", buf, &a, &w);
        string s = buf;
        node tmp = {s, a, w};
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < m; ++i) {
        int nlist, minage, maxage;
        printf("Case #%d:\n", i + 1);
        scanf("%d %d %d", &nlist, &minage, &maxage);
        vector <node> :: iterator it = v.begin();
        int cnt = 0;
        while(cnt < nlist && it != v.end()) {
            if(it->age >= minage && it->age <= maxage) {
                printf("%s %d %d\n", it->name.data(), it->age, it->netWorth);
                cnt++;
            }
            it++;
        }
        if(!cnt) {
            printf("None\n");
        }

    }

}