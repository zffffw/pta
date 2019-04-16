#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct node {
    int grade;
    string name;
    string id;
} node;

vector <node> v;

int n;
int cmp(node a, node b) {
    return a.grade > b.grade;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        char buf1[128], buf2[128];
        int g;
        scanf("%s %s %d", buf1, buf2, &g);
        string n = buf1;
        string id = buf2;
        node tmp={g, buf1, buf2};
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);
    int ming, maxg;
    scanf("%d %d", &ming, &maxg);
    bool flag = false;
    for(int i = 0; i < v.size(); ++i) {
        if(v[i].grade >= ming && v[i].grade <= maxg) {
            printf("%s %s\n", v[i].name.data(), v[i].id.data());
            flag = true;
        }
    }
    if(!flag) {
        printf("NONE\n");
    }
}