#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int K, N;
    scanf("%d", &K);
    while(K--) {
        scanf("%d", &N);
        bool ld[1001] = {0};
        bool rd[1001] = {0};
        bool dd[1001] = {0};
        bool notQ = false;
        for(int i = 1; i <= N; ++i) {
            int a = i, b;
            scanf("%d", &b);
            if(notQ) {
                continue;
            }
            if(dd[b]) {
                // cout << "111" << endl;
                notQ = true;    
                continue;
            } else {
                dd[b] = true;
            }
            int tmp = min(a, b);
            a = a - tmp + 1;
            b = b - tmp + 1;
            // cout << a << ' ' << b << endl;
            if(a >= 1 && a >= b) {
                if(ld[a]) {
                    // cout << "222" << endl;
                    notQ = true;
                    continue;
                } else {
                    ld[a] = true;
                }
            }
            if(b > 1) {
                if(rd[b]) {
                    // cout << "333" << endl;
                    notQ = true;
                    continue;
                } else {
                    rd[b] = true;
                }
            }
        }
        if(notQ)
            printf("NO\n");
        else
            printf("YES\n");
    }
}