#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
int num[2001];
int preorder[4001];
int n;
int curi = 0;
int maxLevel = 0;
void inorder(int k, int level) {
    // cout << k << ' ' << level << endl;
    if(k > n) {
        return ;
    }
    if(level == maxLevel) {
        preorder[k] = num[curi];
        curi ++;
        return ;
    }
    inorder(2*k, level + 1);
    preorder[k] = num[curi++];
    inorder(2*k + 1, level + 1);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
    }
    maxLevel = (int)(log2((double)n)) + 1;
    // cout << maxLevel << endl;
    sort(num, num + n);
    inorder(1, 1);
    queue <int> q;
    bool output = false;
    q.push(1);
    while(!q.empty()) {
        int tmp = q.front();
        q.pop();
        if(!output) {
            cout << preorder[tmp];
            output = true;
        } else {
            cout << ' ' << preorder[tmp];
        }
        if(tmp*2 <= n)
            q.push(tmp*2);
        if(tmp*2 + 1 <= n)
            q.push(tmp*2 + 1);
    }
}