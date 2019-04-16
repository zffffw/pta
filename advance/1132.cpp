#include <iostream>
#include <math.h>
using namespace std;

int n;

int main() {
    long long int num;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%lld", &num);
        int digit = 0;
        long long int tmp = num;
        while(tmp) {
            digit += 1;
            tmp /= 10;
        }
        long long int p = 1;
        for(int i = 0; i < digit/2; ++i) {
            p *= 10;
        }
        long long int A = num / p;
        long long int B = num % p;
        if(A != 0 && B != 0 && num % (A*B) == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}