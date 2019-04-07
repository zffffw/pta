#include <stdio.h>
int main() {
    int g, s, k, a, b, c;
    scanf("%d.%d.%d %d.%d.%d", &g, &s, &k, &a, &b, &c);
    s = k + c >= 29 ? s + 1 : s;
    k = (k + c) % 29;
    g = s + b >= 17 ? g + 1 : g;
    s = (s + b) % 17;
    g += a;
    printf("%d.%d.%d\n", g, s, k);
}