#include <iostream>
using namespace std;

int preorder[50001];
int inorder[50001];
int n;
int curi = 0;
void postOrder(int left, int right) {
    int next = preorder[curi++];
    if(left == right) {
        printf("%d\n", inorder[left]);
        exit(0);
    }
    int divide = -1;
    for(int i = left; i <= right; ++i) {
        if(inorder[i] == next) {
            divide = i;
            break;
        }
    }
    if(divide != left && divide != -1) {
        postOrder(left, divide - 1);
    }
    if(divide != right) {
        postOrder(divide + 1, right);
    }
    printf("%d\n", inorder[divide]);
    exit(0);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &preorder[i]);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &inorder[i]);
    }
    postOrder(0, n - 1);
}