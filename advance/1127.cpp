#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
typedef struct node {
    struct node* lchild;
    struct node* rchild;
    int level;
    int val;
} node;
int inorder[1001];
int postorder[1001];
int n;
int curk;
node* T;

node* createTree(int left, int right, int level) {
    // cout << left << ' ' << right << ' ' << curk << endl;
    node* t = new node;
    t->lchild = NULL;
    t->rchild = NULL;
    if(left == right) {
        t->val = inorder[left];
        t->level = level;
        return t;
    }
    int curval = postorder[curk];
    int mid = -1;
    for(int i = right; i >= left; --i) {
        if(inorder[i] == curval) {
            mid = i;
        }
    }
    if(mid != right && mid != -1) {
        curk--;
        t->rchild = createTree(mid + 1, right, level + 1);
    }
    if(mid != left && mid != -1) {
        curk--;
        t->lchild = createTree(left, mid - 1, level + 1);
    }
    t->val = curval;
    t->level = level;
    return t;
}


void zigzag() {
    queue <node*> q;
    q.push(T);
    vector <int> res;
    stack <int> chg;
    while(!q.empty()) {
        node* curt = q.front();
        q.pop();
        if(curt->lchild)
            q.push(curt->lchild);
        if(curt->rchild)
            q.push(curt->rchild);
        if(curt->level % 2) {
            while(!chg.empty()) {
                res.push_back(chg.top());
                chg.pop();
            }
            res.push_back(curt->val);
        } else {
            chg.push(curt->val);
        }
    }
    while(!chg.empty()) {
        res.push_back(chg.top());
        chg.pop();
    }
    for(int i = 0; i < res.size(); ++i) {
        if(i != 0)
            putchar(' ');
        printf("%d", res[i]);
    }
    putchar('\n');
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &inorder[i]);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &postorder[i]);
    }
    curk = n - 1;
    T = createTree(0, n - 1, 0);
    zigzag();
}