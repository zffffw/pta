#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef struct node {
    string head;
    int val;
    string next;
} node;

vector <node> v;
map <string, node> ma;
int n;
int cmp(node a, node b) {
    return a.val < b.val;
}

int main() {
    char start[128];
    scanf("%d", &n);
    if(n == 0) {
        exit(0);
    }
    scanf("%s", start);
    for(int i = 0; i < n; ++i) {
        int val;
        char buf1[10], buf2[10];
        scanf("%s %d %s", buf1, &val, buf2);
        string he = buf1, ne = buf2;
        node tmp = {he, val, ne};
        map <string, node> :: iterator it = ma.find(he);
        if(it == ma.end())
            ma.insert(make_pair(he, tmp));
    }
    string st = start;
    while(1) {
        map <string, node> :: iterator it = ma.find(st);
        if(it == ma.end()) {
            break;
        }
        string ne = ma[st].next;
        v.push_back(ma[st]);
        st = ne;
    }
    sort(v.begin(), v.end(), cmp);
    if(!v.size()) {
        printf("0 %s\n", start);
        exit(0);
    }
    printf("%lu %s\n", v.size(), v[0].head.data());
    for(int i = 0; i < v.size() - 1; ++i) {
        printf("%s %d %s\n", v[i].head.data(), v[i].val, v[i + 1].head.data());
    }
    printf("%s %d %d\n", v[v.size() - 1].head.data(), v[v.size() - 1].val, -1);

}

