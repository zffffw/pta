#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct node {
    int arrive;
    int begin;
    int serveTime;
    bool operator > (const node &A) const {
        return arrive > A.arrive;
    };
} node;

priority_queue <node, vector <node>, greater <node> > origin, vip;
vector <node> res;
vector <int> vipIdx;
int table, viptable;
int tableCur[105] = {0};
int servNum[105] = {0};
int n;
int getTime(int hour, int min, int sec) {
    return hour*3600 + min*60 + sec;
}

void getFormatTime(int t, int& hour, int& min, int& sec) {
    hour = t / 3600;
    min = (t % 3600)/60;
    sec = ((t % 3600) % 60);
}


void simulate() {
    int st = 28800;
    for(int i = st; i < 75600; ++i) {
        for(int j = 0; j < table; ++j) {
            if(tableCur[j] == i) {
                // servNum[j] ++;
                tableCur[j] = 0;
            }
        }
        // cout << vip.top().arrive << ' ' << i << endl;
        while(!vip.empty() && i >= vip.top().arrive) {
            node tmp = vip.top();
            bool flag = false;
            // cout << tmp.arrive << ' ' << i << endl;
            for(int j = 0; j < vipIdx.size(); ++j) {
                int k = vipIdx[j];
                if(tableCur[k] == 0) {
                    tableCur[k] = i + tmp.serveTime;
                    tmp.begin = i;
                    // cout << i << "**" << endl;
                    res.push_back(tmp);
                    servNum[k] ++;
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                break;
            } else {
                vip.pop();
            }
        }
        while((!vip.empty() && i >= vip.top().arrive) || (!origin.empty() && i >= origin.top().arrive)) {
            node tmp;
            bool isVIP;
            if((!vip.empty() && i >= vip.top().arrive) && (!origin.empty() && i >= origin.top().arrive)) {
                tmp = vip.top().arrive < origin.top().arrive ? vip.top() : origin.top();
                bool isVIP = vip.top().arrive < origin.top().arrive;
            } else if(!vip.empty() && i >= vip.top().arrive) {
                tmp = vip.top();
                isVIP = true;
            } else {
                tmp = origin.top();
                isVIP = false;
            }
            bool flag = false;
            for(int j = 0; j < table; ++j) {
                if(tableCur[j] == 0) {
    
                    tableCur[j] = i + tmp.serveTime;
                    tmp.begin = i;
                    servNum[j] ++;
                    // cout << i << "**" << endl;
                    res.push_back(tmp);
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                break;
            } else {
                if(isVIP)
                    vip.pop();
                else
                    origin.pop();
            }
        }
    }
    for(int i = 0; i < res.size(); ++i) {
        int h1, m1, s1, h2, m2, s2;
        // cout << res[i].arrive << ' ' << res[i].begin << endl;
        getFormatTime(res[i].arrive, h1, m1, s1);
        getFormatTime(res[i].begin, h2, m2, s2);
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", h1, m1, s1, h2, m2, s2, (res[i].begin - res[i].arrive + 30) / 60);
    }
    for(int i = 0; i < table; ++i) {
        if(i != 0)
            putchar(' ');
        printf("%d", servNum[i]);
    }
    putchar('\n');
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int h, m, s;
        int isVIP;
        int lastT;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &lastT, &isVIP);
        int ti = getTime(h, m, s);
        lastT = lastT > 120 ? 120 : lastT;
        node tmp = {ti, 0, lastT*60};
        if(isVIP)
            vip.push(tmp);
        else
            origin.push(tmp);
    }
    scanf("%d %d", &table, &viptable);
    // scanf("%d", &table);
    for(int i = 0; i < viptable; ++i) {
        int tmp;
        scanf("%d", &tmp);
        vipIdx.push_back(tmp - 1);
    }
    sort(vipIdx.begin(), vipIdx.end());
    // while(!origin.empty()) {
    //     int h, m, s;
    //     getFormatTime(origin.top().arrive, h, m, s);
    //     printf("%02d:%02d:%02d %d\n", h, m, s, origin.top().serveTime);
    //     origin.pop();
    // }
    // while(!vip.empty()) {
    //     int h, m, s;
    //     getFormatTime(vip.top().arrive, h, m, s);
    //     printf("%02d:%02d:%02d %d\n", h, m, s, vip.top().serveTime);
    //     vip.pop();
    // }
    simulate();
}