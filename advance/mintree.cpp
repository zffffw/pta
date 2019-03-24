#include <iostream>
using namespace std;
#define INF 10000
int map[51][51];
int visit[51];
int vexNum, edgeNum;

void initMap() {
    for(int i = 1; i <= 50; ++i) {
        visit[i] = 0;
        for(int j = 1; j <= 50; ++j) {
            if (i != j)
                map[i][j] = INF;
            else 
                map[i][j] = 0;
        }
    }
}

void Kruskal() {

}


void Prim() {
    visit[1] = 1;
    int sum = 0;
    int count = 1;
    for(int i = 1; i < vexNum; ++i) {
        int minv1, minv2, minval=INF;
        for(int j = 1; j <= vexNum; ++j) {
            if(visit[j] == 1) {
                for(int k = 1; k <= vexNum; ++k) {
                    if(map[j][k] < minval && j != k && ! visit[k]) {
                        minv1 = j;
                        minv2 = k;
                        minval = map[j][k];
                    }
                }
            }
        }
        visit[minv2] = 1;
        // cout << minval << endl;
        sum += minval;
    }
    if(vexNum == 1) {
        cout << 0 << endl;
    } else {
        cout << sum << endl;
    }    
}

int main() {
    int v1, v2, value;
    int tmp;
    while(1) {
        scanf("%d", &vexNum);
        if (vexNum == 0) {
            break;
        }
        initMap();
        scanf("%d", &edgeNum);
        for(int i = 1; i <= edgeNum; ++i) {
            // cin >> v1 >> v2 >> value;
            scanf("%d %d %d", &v1, &v2, &value);
            if(map[v1][v2] > value) {
                map[v1][v2] = map[v2][v1] = value;
            }
        }
        // getchar();
        Prim();
    }
}