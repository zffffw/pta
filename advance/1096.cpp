#include <iostream>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int fac = 2;
    int one = 1;
    while(n > 1) {
        while(n % fac == 0) {
            if(one)
                printf("%d", fac);
            else 
                printf("*%d", fac);
            one = 0;
            n /= fac;
        }
        fac ++;
    }
    putchar('\n');
}