#include <iostream>
#include <vector>
using namespace std;
typedef struct node {
    int pos;
    int val;
    int next;
} node;

int main() {
    int start, n;
    node list[100001];
    vector <node> ve[2];
    scanf("%d %d", &start, &n);
    for(int i = 0; i < n; ++i) {
        int p, v, n;
        scanf("%d %d %d", &p, &v, &n);
        node tmp = {p, v, n};
        list[p] = tmp;
    }
    int cpos = start;
    bool flag[10001] = {0};
    while(cpos != -1) {
        int v = list[cpos].val;
        v = v < 0 ? -v : v;
        if(!flag[v]) {
            ve[0].push_back(list[cpos]);
            flag[v] = true;
        } else {
            ve[1].push_back(list[cpos]);
        }
        cpos = list[cpos].next;
    }   
    for(int i = 0; i < 2; ++i) {
        int next;
        for(int j = 0; j < ve[i].size(); ++j) {
            if(j == ve[i].size() - 1)
                printf("%05d %d -1\n", ve[i][j].pos, ve[i][j].val);
            else {
                next = ve[i][j + 1].pos;
                printf("%05d %d %05d\n", ve[i][j].pos, ve[i][j].val, next);
            }
        }
    }

    
}