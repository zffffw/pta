#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct node {
    int lchild;
    int rchild;
    int lnum;
    int rnum;
    int val;
} node;
node tree[10001];
int num[10001];
int n;
void init() {
    for(int i = 0; i < n; ++i) {
        tree[i].lchild = -1;
        tree[i].rchild = -1;
        tree[i].lnum = 0;
        tree[i].rnum = 0;
        tree[i].val = 0;
    }
}
int preorder(int k) {
    // cout << k << ' ' << endl;
    if(tree[k].lchild == -1 && tree[k].rchild == -1) {
        // cout << k << endl;
        return 1;
    }
    if(tree[k].lchild != -1) {
        tree[k].lnum += preorder(tree[k].lchild);
    }
    if(tree[k].rchild != -1) {
        tree[k].rnum += preorder(tree[k].rchild);
    }
    // cout << tree[k].rnum << endl;
    return tree[k].lnum + tree[k].rnum + 1;
}

void getRes(int left, int right, int k) {
    // cout << left << ' ' << right << ' ' << k << endl;
    if(left == right) {
        // printf("%d ", num[left]);
        tree[k].val = num[left];
        return ;
    }
    int cur = tree[k].lnum + left;
    // printf("%d ", num[cur]);
    tree[k].val = num[cur];
    int lleft = left, lright = cur - 1;
    int rleft = cur + 1, rright = right;
    if(tree[k].lnum) {
        getRes(lleft, lright, tree[k].lchild);
    }
    if(tree[k].rnum) {
        getRes(rleft, rright, tree[k].rchild);
    }
}



int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &tree[i].lchild, &tree[i].rchild);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
    }
    sort(num, num + n);
    // for(int i = 0; i < n; ++i) {
    //     cout << num[i] << ' ';
    // }
    // cout << endl;
    // for(int i = 0; i < n; ++i) {
    //     cout << tree[i].lnum << ' ' << tree[i].rnum << endl;
    // }
    // cout << "*****" << endl;
    preorder(0);
    getRes(0, n - 1, 0);
    // for(int i = 0; i < n; ++i) {
    //     cout << tree[i].lnum << ' ' << tree[i].rnum << ' ' << tree[i].val << endl;
    // }
    queue <int> q;
    q.push(0);
    bool output = false;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(tree[cur].lchild != -1) {
            q.push(tree[cur].lchild);
        }
        if(tree[cur].rchild != -1) {
            q.push(tree[cur].rchild);
        }
        if(output) {
            putchar(' ');
        }
        printf("%d", tree[cur].val);
        output = true;
    }
}   