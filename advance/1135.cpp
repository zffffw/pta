#include <iostream>
using namespace std;
int n;
int maxn;
int preorder[1001];
int num[1001];
int tree[1001] = {0};
bool flag = true;
int curd = 0;
int dd = -1;
void preTravel(int left, int right, int k) {
    // if(k >= maxn) {
    //     return ;
    // }
    // cout << num[left] << ' ';
    tree[k] = num[left];
    if(left == right) {
        return ;
    }
    int mid = -1;
    int tmp = preorder[left];
    for(int i = left + 1 ; i <= right; ++i) {
        if(preorder[i] > tmp) {
            mid = i;
            break;
        }
    }
    if(mid == -1) {
        preTravel(left + 1, right, 2*k);
    } else if(mid != left + 1) {
        preTravel(left + 1, mid - 1, 2*k);
        preTravel(mid, right, 2*k + 1);
    } else {
        preTravel(left + 1, right, 2*k + 1);
    }
}

void preT(int k) {
    // cout << k << "**" << tree[k] << endl;
    // cout << dd << ' ' << curd << endl;
    if(!tree[k]) {
        // cout << curd + 1 << endl;
        // cout << dd << ' ' << curd << endl;
        if(dd == -1) {
            dd = curd + 1;
        } else if(dd != curd + 1) {
            flag = false;
        }
        return ;
    }
    if(tree[k] > 0) {
        curd ++;
    }
    // cout << tree[k]  << ' ';
    if(tree[k] < 0) {
        if((tree[2*k] && tree[2*k] < 0) || (tree[2*k + 1] && tree[2*k + 1] < 0)) {
            flag = false;
            // cout << "111" << endl;
        }
    }
    // if(!tree[2*k] && !tree[2*k + 1]) {
    //     if(tree[k] < 0) {
    //         flag = false;
    //         cout <<  "222" << endl;
    //     }
    // }
    preT(2*k);
    preT(2*k + 1);
    if(tree[k] > 0) {
        curd --;
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &maxn);
        curd = 0;
        dd = -1;
        flag = true;
        for(int j = 0; j <= 1000; ++j) {
            preorder[j] = 0;
            num[j] = 0;
            tree[j] = 0;
        }
        for(int j = 0; j < maxn; ++j) {
            int tmp;
            scanf("%d", &tmp);
            num[j] = tmp;
            tmp = tmp < 0 ? -tmp : tmp;
            preorder[j] = tmp;
        }
        preTravel(0, maxn - 1, 1);
        if(num[0] < 0) {
            flag = false;
        }
        
        preT(1);
        if(!flag) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}