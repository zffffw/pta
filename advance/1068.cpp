#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[10010][105] = {0};
bool has[10010][105] = {false};
int n, m;
vector <int> v;
int cmp(int a, int b) {
    return a > b;
}

void init() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            dp[i][j] = 0;
        }
    }
}
// 动态规划: 递推公式为 d[i][j] = max(d[i - 1][j], d[i - 1][j - c[i]] + c[i], c[i]), d[i][j]表示前i个硬币不超过j价值的最大价值。
int main() {
    scanf("%d %d", &n, &m);
    init();
    for(int i = 1; i <= n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);
    // for(int i = 0; i < v.size(); ++i) {
    //     cout << v[i] << ' ';
    // }
    // cout << endl;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(j - v[i - 1] >= 0 && dp[i - 1][j - v[i - 1]] + v[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + v[i - 1]);
                if(dp[i][j] == dp[i - 1][j - v[i - 1]] + v[i - 1]) 
                    has[i][j] = true;
            else if(v[i - 1] <= j){
                dp[i][j] = max(dp[i - 1][j], v[i - 1]);
                if(dp[i][j] == v[i - 1]) 
                    has[i][j] = true;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // for(int i = 1; i <= n; ++i) {
    //     printf("%3d ", v[i - 1]);
    //     for(int j = 1; j <= m; ++j) {
    //         printf("(%3d %d) ", dp[i][j], has[i][j]);
    //     }
    //     putchar('\n');
    // }
    if(dp[n][m] == m) {
        int nowi = n, nowj = m;
        vector <int> res;
        while(nowj != 0) {
            if(has[nowi][nowj]) {
                res.push_back(v[nowi - 1]);
                nowj -= v[nowi - 1];
            }
            nowi --;
        }
        cout << res[0];
        for(int i = 1; i < res.size(); ++i) {
            cout<< ' ' << res[i] ;
        }
        cout << endl;
    } else {
        printf("No Solution\n");
    }
    
    // printf("%d\n", dp[n][m]);
    
}