#include <iostream>
#include <vector>
using namespace std;

int map[201][201];

int n, m, k;

int main() {
    scanf ("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
        map[b][a] = 1;
    }

    scanf("%d", &k);
    for(int i = 0; i < k; ++i) {
        int vn;
        scanf("%d", &vn);
        vector <int> vexs;
        for(int j = 0; j < vn; ++j) {
            int tmp;
            scanf("%d", &tmp);
            vexs.push_back(tmp);
        }
        int flag = 2;
        for(int j = 0; j < vexs.size(); ++j) {
            bool tflag = true;
            for(int w = 0; w < vexs.size(); ++w) {
                if(j != w) {
                    if(!map[vexs[j]][vexs[w]]) {
                        tflag = false;
                        break;
                    }
                }
            }
            if(!tflag) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            for(int j = 1; j <= n; ++j) {
                bool tflag = true;
                for(int w = 0; w < vexs.size(); ++w) {
                    if(j == vexs[w]) {
                        tflag = false;
                        break;
                    }
                }
                if(!tflag) {
                    continue;
                }
                for(int w = 0; w < vexs.size(); ++w) {
                    if(!map[j][vexs[w]]) {
                        tflag = false;
                        break;
                    }
                }
                if(!tflag) {
                    continue;
                } else {
                    flag = 1;
                    break;
                }
            }
        }
        switch (flag)
        {
            case 0: {
                printf("Not a Clique\n");
            }break;
            case 1: {
                printf("Not Maximal\n");
            } break;
            case 2: {
                printf("Yes\n");
            }break;
        }
    }
}