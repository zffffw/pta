#include <iostream>
using namespace std;

int n;

int main() {
    double ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        double tmp;
        scanf("%lf", &tmp);
        ans += tmp*i*(n - i + 1);
    }
    printf("%.2lf\n", ans);
}