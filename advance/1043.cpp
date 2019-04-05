#include <iostream>
#include <vector>
using namespace std;

typedef struct node {
    int key;
    struct node *lchild;
    struct node *rchild;
} node;

enum direc{LEFT, RIGHT};
int keys[1001];
int n;
typedef node * tree;
int flagBST = 1;
int flagMIBST = 1;
vector <int> res;


tree isBST(int left, int right, int pre, int dire) {
    int now = keys[left];
    int divide = left;
    tree p = new node;
    p->key = now;

    for(int i = left + 1; i <= right; ++i) {
        if(keys[i] >= now) {
            divide = i;
            break;
        }
    }
    // cout << now << ' ' << left << ' ' << divide << ' ' << right << ' ' << pre << ' ' << dire << endl;
    // getchar();
    if(divide != left) {
        for(int j = divide; j <= right; ++j) {
            if(now > keys[j]) {
                flagBST = 0;
                break;
            }
        }
    }
    if(left == right) {
        p->lchild = NULL;
        p->rchild = NULL;
        return p;
    }
    if(divide == left) {
        p->lchild = isBST(left + 1, right, now, LEFT);
    } else if (divide != left + 1) {
        p->lchild = isBST(left + 1, divide - 1, now, LEFT);
    } else {
        p->lchild = NULL;
    }
    if(divide != left) {
        p->rchild = isBST(divide, right, now, RIGHT);
    } else {
        p->rchild = NULL;
    }
    return p;
}



tree isMIBST(int left, int right, int pre, int dire) {
    int now = keys[left];
    int divide = left;
    tree p = new node;
    p->key = now;
    for(int i = left + 1; i <= right; ++i) {
        if(keys[i] < now) {
            divide = i;
            break;
        }
    }
    // cout << now << ' ' << left << ' ' << divide << ' ' << right << ' ' << pre << endl;
    // getchar();
    if(divide != left) {
        for(int j = divide; j <= right; ++j) {
            if(now <= keys[j]) {
                flagMIBST = 0;
                break;
            }
        }
    }
    if(left == right) {
        p->lchild = NULL;
        p->rchild = NULL;
        return p;
    }

    if(divide == left) {
        p->lchild = isMIBST(left + 1, right, now, LEFT);
    } else if (divide != left + 1) {
        p->lchild = isMIBST(left + 1, divide - 1, now, LEFT);
    } else {
        p->lchild = NULL;
    }
    if(divide != left) {
        p->rchild = isMIBST(divide, right, now, RIGHT);
    } else {
        p->rchild = NULL;
    }
    return p;
}


void postOrderTravel(tree p) {
    if(!p) {
        return ;
    }
    if(p->lchild) {
        postOrderTravel(p->lchild);
    }
    if(p->rchild) {
        postOrderTravel(p->rchild);
    }
    res.push_back(p->key);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &keys[i]);
    }
    tree tr1 = isBST(1, n, 0, -1);
    tree tr2 = isMIBST(1, n, 0, -1);
    // cout << flagBST << ' ' << flagMIBST << endl;
    if(flagBST) {
        postOrderTravel(tr1);
        cout << "YES" << endl;
        cout << res[0];
        for(int i = 1; i < res.size(); ++i) {
            cout << ' ' << res[i];
        }   
        cout << endl;

    } else if (flagMIBST) {
        postOrderTravel(tr2);
        cout << "YES" << endl;
        cout << res[0];
        for(int i = 1; i < res.size(); ++i) {
            cout << ' ' << res[i];
        }   
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    // postOrderTravel(tr2);
    // cout << res[0];
    // for(int i = 1; i < res.size(); ++i) {
    //     cout << ' ' << res[i];
    // }   
    // cout << endl;


}