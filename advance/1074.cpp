#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef struct node {
    int pos;
    int val;
    int next;
    bool flag;
} node;
//有些结点不在链表上，不能直接用n
node num[100001] = {0};
node order[100001] = {0};
int start, n, k;
int main() {
    scanf("%d %d %d", &start, &n, &k);
    for(int i = 1; i <= 100000; ++i) {
        num[i].pos = -1;
        num[i].next = -1;
    }
    for(int i = 0; i < n; ++i) {
        int p, v, nxt;
        scanf("%d %d %d", &p, &v, &nxt);
        num[p].pos = p;
        num[p].val = v;
        num[p].next = nxt;
    }
    int curp = start; //当前位置
    int cnt = 1;
    while(curp != -1) {
        if(num[curp].pos != -1) {
            order[cnt++] = num[curp];
            curp = num[curp].next;
        } else {
            break;
        }
    }
    // for(int i = 1; i <= n; ++i) {
    //     cout << order[i].val << ' ' << order[i].pos << endl;;
    // }
    // cout << endl;
    if(cnt == 1)
        exit(0);
    for(int i = 1; i <= (cnt - 1) / k; ++i) {
        // cout << i << endl;
        for(int j = i*k; j >= i*k - k + 1; --j){
            printf("%05d %d ", order[j].pos, order[j].val);
            if(j == i*k - k + 1 && i*k != (cnt - 1)) {
                if(i == (cnt - 1)/k)
                    printf("%05d\n", order[i*k + 1].pos);
                else
                    printf("%05d\n", order[(i + 1)*k].pos);
            }
            else if(j == i*k - k + 1 && i*k == (cnt - 1))
                printf("-1\n");
            else
                printf("%05d\n", order[j - 1].pos);
        }
    }
    for(int i = (cnt - 1) / k * k + 1; i <= (cnt - 1); ++i) {
        printf("%05d %d ", order[i].pos, order[i].val);
        if(i == (cnt - 1)) 
            printf("-1\n");
        else
            printf("%05d\n", order[i + 1].pos);
    }
}