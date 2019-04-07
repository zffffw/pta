#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef struct node {
    string name;
    friend bool operator < (node a, node b) {
        return a.name > b.name;
    }
}node;
typedef priority_queue <node> que;
map <int, que> cmap;
int n, m;
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        que tmp_que;
        cmap.insert(make_pair(i, tmp_que));
    }
    for(int i = 0; i < n; ++i) {
        char buf[128];
        int k;
        scanf("%s %d", buf, &k);
        string name = buf;
        for(int j = 0; j < k; ++j) {
            int course;
            scanf("%d", &course);
            map <int, que> :: iterator it = cmap.find(course);
            node tmp = {name};
            it->second.push(tmp);
        }
    }
    map <int, que> :: iterator it = cmap.begin();
    while(it != cmap.end()) {
        printf("%d %lu\n", it->first, it->second.size());
        while(!it->second.empty()) {
            printf("%s\n", it->second.top().name.data());
            it->second.pop();
        }
        it++;
    }
}