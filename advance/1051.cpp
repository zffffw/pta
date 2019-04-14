#include <iostream>
#include <vector>
using namespace std;

// 分段观察，比如3 2 1 7 5 6 4可以分成 3 2 1 和 7 5 6 4，满足两个条件才正确，1----- 3 > 2 > 1 and 7 > 5 > 6 > 4 显然不对, 
//  2------每一段的长度要小于等于规定的长度M，否则栈放不下
int n, m, k;
int order[1001];
int main() {
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 0; i < k; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &order[j]);
        }
        int cv = 0;
        int flag = true;
        for(int j = 1; j <= n; ++j) {
            if( (j == n && cv != n - 1) || (j < n && order[j] > order[cv]) ) {
                if(j - cv > m) {
                    flag = false;
                } else {
                    for(int k = cv; k < j - 1; ++k) {
                        if(order[k] < order[k + 1]) {
                            flag = false;
                            break;
                        }
                    }
                }
                if(!flag) {
                    break;
                }
                cv = j;
            }
        }
        if(!flag) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

}