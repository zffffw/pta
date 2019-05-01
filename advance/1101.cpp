#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
int num[100003];
int mintree[100003];
int maxtree[100003];
int n;
void init() {
    for(int i = 1; i <= n + 2; ++i) {
        mintree[i] = INT_MAX - 1;
        maxtree[i] = 0;
    }
}
int main() {
    scanf("%d", &n);
    init();
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &num[i]);
        // mintree[i] = min(num[i], mintree[i - 1]);
        maxtree[i] = max(num[i], maxtree[i - 1]);
    }
    for(int i = n; i >= 1; --i) {
        mintree[i] = min(num[i], mintree[i + 1]);
    }
    vector <int> res;
    for(int i = 1; i <= n; ++i) {
        int rminv = mintree[i + 1], lmaxv = maxtree[i - 1];
        if(i == 1) {
            if(rminv > num[i]) {
                res.push_back(num[i]);
            }
        } else if (i == n) {
            if(lmaxv < num[i]) {
                res.push_back(num[i]);
            }
        } else {
            if(lmaxv < num[i] && rminv > num[i]) {
                res.push_back(num[i]);
            }
        }
    }
    printf("%lu\n", res.size());
    sort(res.begin(), res.end());
    for(int i = 0; i < res.size(); ++i) {
        if(i != 0)
            putchar(' ');
        printf("%d", res[i]);
    }
    putchar('\n');

}