#include <iostream>
using namespace std;

int n, m, l;
int color[201];
int strip[10001];
int d[201][10001];
int main() {
    scanf("%d %d", &n, &l);
    for(int i = 1; i <= l; ++i) {
        scanf("%d", &color[i]);
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%d", &strip[i]);
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            
            if(color[i] == strip[j]) {
                d[i][j] = max(d[i - 1][j - 1], max(d[i][j - 1], d[i - 1][j])) + 1;
            } else {
                d[i][j] = max(d[i - 1][j - 1], max(d[i][j - 1], d[i - 1][j])) ;
            }
        }
    }
    // for(int i = 1; i <= n; ++i) {
    //     for(int j = 1; j <= m; ++j) {
    //         cout << d[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    printf("%d\n", d[n][m]);
}