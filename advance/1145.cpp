#include <iostream>
using namespace std;

int hashtable[10010] = {0};
int n, m, k;
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
    scanf("%d %d %d", &n, &m, &k);
    while(!isPrime(n)) {
        n++;
    }
    // cout << n << endl;
    for(int i = 0; i < m; ++i) {
        int tmp;
        scanf("%d", &tmp);
        bool find = false;
        for(int j = 0; j <= n - 1; ++j) {
            int tpos = (tmp % n + j*j) % n;
            if(!hashtable[tpos]) {
                find = true;
                hashtable[tpos] = tmp;
                break;
            }
        }
        if(!find) {
            printf("%d cannot be inserted.\n", tmp);
        }
    }
    int totaltime = 0;
    for(int i = 0; i < k; ++i) {
        int tmp;
        scanf("%d", &tmp);
        int j;
        // int count = 0;
        for(j = 0; j <= n - 1; ++j) {
            int tpos = (tmp % n + j * j) % n;
            // totaltime ++;
            // count ++;
            if(hashtable[tpos] == tmp || hashtable[tpos] == 0) {
                break;
            }
        }
        totaltime += j + 1;
        // cout << j + 1 <<  ' ' << count << endl;
    }
    if(k == 0) {
        printf("0.0\n");
    } else {
        printf("%.1f\n", totaltime / (float)k);
    }
}