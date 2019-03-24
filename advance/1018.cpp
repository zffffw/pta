#include <iostream>
#include <vector>
#include <math.h>
#define INF 1000000
using namespace std;


int map[502][502];
int lastPoint[502];
int curBike[502];
int visit[502];
int shortestWeight[502];
int sum[502];
int maxCapa, vexNum, targetVex, roadNum;

void initData() {
    for(int i = 0; i <= vexNum; ++i) {
        visit[i] = 0;
        shortestWeight[i] = INF;
        lastPoint[i] = -1;
        sum[i] = 0;
    }
}



void dijkstra(int start) {
    lastPoint[start] = 0;

    shortestWeight[start] = 0;
    for(int i = 0; i <= vexNum; ++i) {
        int minweight = INF, curPoint;
        for(int j = 0; j <= vexNum; ++j) {
            if (minweight > shortestWeight[j] && !visit[j]) {
                curPoint = j;
                minweight = shortestWeight[j];
            }
        }
        // cout << "short:" ;
        // for(int i = 0; i <= vexNum; ++i) {
        //     cout << ' ' << shortestWeight[i];
        // }
        // cout << endl << "last:";
        // for(int i = 0; i <= vexNum; ++i) {
        //     cout << ' ' << lastPoint[i];
        // }
        // cout << endl << curPoint << endl;
        visit[curPoint] = 1;
        for(int j = 0; j <= vexNum; ++j) {
            if(!visit[j] && map[curPoint][j] > 0  && shortestWeight[j] > shortestWeight[curPoint] + map[curPoint][j]) {
                shortestWeight[j] = shortestWeight[curPoint] + map[curPoint][j];
                lastPoint[j] = curPoint;
                sum[j] = sum[curPoint] + curBike[j];
            } else if (!visit[j] && map[curPoint][j] > 0  && shortestWeight[j] == shortestWeight[curPoint] + map[curPoint][j] && abs(sum[j]) > abs(sum[curPoint] + curBike[j])) {
                lastPoint[j] = curPoint;
                sum[j] = sum[curPoint] + curBike[j];
            }
        }
    }
    // cout << sum[targetVex] << endl;
}

void printRoad(int p) {
    if(p != 0) {
        printRoad(lastPoint[p]);
        cout << "->" << p ;
    } else {
        cout << p ;
    }
}

void printRes() {
    if(sum[targetVex] < 0) {
        cout << -sum[targetVex] << ' ';
    } else {
        cout << 0 << ' ';
    }
    printRoad(targetVex);
    cout << ' ';
    if(sum[targetVex] > 0) {
        cout << sum[targetVex] << endl;
    } else {
        cout << 0 << endl;
    }
}

int main() {
    cin >> maxCapa >> vexNum >> targetVex >> roadNum;
    for(int i = 1; i <= vexNum; ++i) {
        cin >> curBike[i];
        curBike[i] -= maxCapa/2;
    }
    initData();
    for(int i = 0; i < roadNum; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        map[a][b] = w;
        map[b][a] = w;
    }
    dijkstra(0);
    printRes();
}