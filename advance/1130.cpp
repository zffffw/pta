#include <iostream>
#include <string>
using namespace std;
typedef struct node {
    char s[11];
    int left;
    int right;
} node;
node arr[21];
int n;
int start;
string res;

void search(int p) {
    if(p == 0) {
        return ;
    }
    // cout << p << endl;
    if(p != start && (arr[p].left != -1 || arr[p].right != -1)) {
        res += '(';
    }
    if(arr[p].left != -1) {
        search(arr[p].left);
    }
    res += arr[p].s;
    if(arr[p].right != -1) {
        search(arr[p].right);
    }
    if(p != start && (arr[p].left != -1 || arr[p].right != -1)) {
        res += ')';
    }
}

int main() {
    scanf("%d", &n);
    bool flag[21] = {0};
    for(int i = 1; i <= n; ++i) {
        scanf("%s %d %d", arr[i].s, &arr[i].left, &arr[i].right);
        if(arr[i].left != -1) {
            flag[arr[i].left] = 1;
        }
        if(arr[i].right != -1) {
            flag[arr[i].right] = 1;
        }
    }
    
    for(int i = 1; i <= n; ++i) {
        if(!flag[i]) {
            start = i;
            break;
        }
    }
    // cout << "111" << endl;
    // cout << start << endl;
    search(start);
    cout << res << endl;

}