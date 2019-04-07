#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef struct customer {
    int id;
    int beginTime;
    int processTime;
    int tt;
    friend bool operator < (customer a, customer b) {
        return a.beginTime > b.beginTime;
    }
} customer;

queue <customer> window[101];
queue <customer> waitList;
priority_queue <customer> clist;
int ok[10001];
int waitTime[10001];
int n, m;

// 按照秒来模拟，先创造一个排队队列，保证这些人必须完成任务，然后模拟直到队列为空

void simulate() {
    int startTime = 8*3600;
    int endTime = 17*3600;
    while(!clist.empty()) { 
        if(clist.top().beginTime <= endTime)
            waitList.push(clist.top());
        clist.pop();
    }
    for(int tt = startTime; !waitList.empty(); ++tt) {
        for(int ww = 0; ww < m; ++ww) {
            if(!window[ww].empty() && window[ww].front().tt == tt) {
                window[ww].pop();
                if(!waitList.empty() && waitList.front().beginTime <= tt) {
            
                    customer tmp = waitList.front();
                    ok[tmp.id] = 1;
                    tmp.tt = tt + tmp.processTime;
                    waitTime[tmp.id] += tt - tmp.beginTime;
                    window[ww].push(tmp);
                    waitList.pop();
                }
            } else if (window[ww].empty() ) {
                if(!waitList.empty() && waitList.front().beginTime <= tt) {
                    customer tmp = waitList.front();
                    ok[tmp.id] = 1;
                    tmp.tt = tt + tmp.processTime;
                    waitTime[tmp.id] += tt - tmp.beginTime;
                    window[ww].push(tmp);
                    waitList.pop();
                }
            }
        }

    }
    int sumWait = 0;
    float count = 0;
    for(int i = 1; i <= n; ++i) {
        if(ok[i]) { 
            sumWait += waitTime[i];
            count ++;
        }
    }
    printf("%.1f\n", sumWait/60.0/count);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        int hh, mm, ss, tt;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &tt);
        customer tmp;
        tmp.beginTime = hh*3600+mm*60+ss;
        tmp.processTime = tt*60;
        tmp.id = i;
        clist.push(tmp);
    }
    simulate();
}

