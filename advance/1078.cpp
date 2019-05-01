#include <iostream>
using namespace std;
bool flag[10100] = {0};
bool isPrime(int n) {
    if(n == 1) {
        return false;
    }
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            return false;
        }    
    }
    return true;
}

int main() {
    int msize, n;
    scanf("%d %d", &msize, &n);
    while(!isPrime(msize)) {
        msize ++;
    }
    // cout << msize << endl;
    bool output = false;
    for(int i = 0; i < n; ++i) {
        long long  tmp;
        scanf("%lld", &tmp);
        int k = tmp % msize;
        if(flag[k]) {
            bool find = 0;
            int p;
            for(int step = 0; step < msize; ++step) {
                p = (k + step * step) % msize;
                if(!flag[p]) {
                    flag[p] = true;
                    find = true;
                    if(output) {
                        printf(" %d", p); 
                    } else {
                        printf("%d", p);
                    }
                    break;
                }
            }
            if(!find) {
                printf(" -");
            }
        } else {
            flag[k] = true;
            if(output) {
                printf(" %d", k);
            } else {
                printf("%d", k);
                output = true;
            }
        }
    }
}