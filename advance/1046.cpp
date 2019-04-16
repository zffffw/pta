#include <iostream>
using namespace std;

int d[100001];
int n;

int main() {
    scanf("%d", &n);
    int sum = 0;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &d[i]);
        sum += d[i];
        d[i] = d[i] + d[i - 1];
    }
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a > b) {
            swap(a, b);
        }
        int tmpsum = d[b - 1] - d[a - 1];
        int res = tmpsum < sum - tmpsum ? tmpsum : sum - tmpsum;
        printf("%d\n", res);
    }
}