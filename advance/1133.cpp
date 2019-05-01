#include <iostream>
#include <vector>
using namespace std;
typedef struct node {
    int pos;
    int val;
    int next;
} node;

vector <node> v[3];
node list[100001];
int n, start, K;

int main() {
    scanf("%d %d %d", &start, &n, &K);
    for(int i = 0; i < n; ++i) {
        int s, v, n;
        scanf("%d %d %d", &s, &v, &n);
        node tmp = {s, v, n};
        list[s] = tmp;
    }
    int cnt = 0;
    int cpos = start;
    while(cpos != -1) {
        if(list[cpos].val < 0) {
            v[0].push_back(list[cpos]);
        } else if(list[cpos].val >= 0 && list[cpos].val <= K) {
            v[1].push_back(list[cpos]);
        } else {
            v[2].push_back(list[cpos]);
        }
        cpos = list[cpos].next;
    }
    int next;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < v[i].size(); ++j) {
            if(j < v[i].size() - 1)
                next = v[i][j + 1].pos;
            else {
                if(i == 0 && v[1].size()) {
                    next = v[1][0].pos;
                } else if((i == 1 || i == 0) && v[2].size()) {
                    next = v[2][0].pos;
                } else {
                    next = -1;
                }
            }
            if(next != -1)
                printf("%05d %d %05d\n", v[i][j].pos, v[i][j].val, next);
            else 
                printf("%05d %d -1\n", v[i][j].pos, v[i][j].val);
        }
    }
}