#include <iostream>
using namespace std;



int main() {
    long long int n;
    scanf("%lld", &n);
    // cout << n << endl;
    long long int begin = n;
    int maxlen = 1;
    for(long long int i = 2; i * i <= n; ++i) {
        long long int tmp = n;
        long long int j;
        for(j = i; tmp % j == 0 ; ++j) {
            tmp /= j;
        }
        if((j - i == maxlen && i < begin) || j - i > maxlen) {
            maxlen = j - i;
            begin = i;
        }
    }
    bool output = false;
    printf("%d\n", maxlen);
    for(int i = begin; i < begin + maxlen; ++i) {
        if(output)
            putchar('*');
        printf("%d", i);
        output = true;
    }
    putchar('\n');
}