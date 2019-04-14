#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef struct node {
    int pos;
    char c;
    int next;
    bool flag;
} node;
// vector <node> v;
node total[100001];
int start1, start2;
int n;
int main() {
    scanf("%d %d %d", &start1, &start2, &n);
    bool flag=false;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        int a, b;
        char c;
        scanf("%d %c %d", &a, &c, &b);
        node tmp={a, c, b, 0};
        total[a] = tmp;
    }
    int k = start1;
    while(k != -1) {
        total[k].flag = true;
        k = total[k].next;
    }
    k = start2;
    int find = 0;
    while(k != -1) {
        if(total[k].flag) {
            find = 1;
            printf("%05d\n", total[k].pos);
            break;
        }
        k = total[k].next;
    }
    if(!find) {
        printf("-1\n");
    }
    
}