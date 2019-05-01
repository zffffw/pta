#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#define INTMAX 1000000
using namespace std;

map <string, int> str2idx;
float node[202];

int d[202];
float hapen[202];
int nodenum[202];
int shortestnum[202];
int n, m;
int edge[202][202];
int last[202];
string start;
bool visit[202];
int getIdx(string name) {
    return str2idx[name];
}
string getStr(int idx) {
    map < string, int > :: iterator it = str2idx.begin();
    while(it->second != idx) {
        it++;
    }
    return it->first;
}
void init() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            edge[i][j] = INTMAX;
        }
        hapen[i] = node[i];
        nodenum[i] = 0;
        shortestnum[i] = 1;
        d[i] = INTMAX;
        visit[i] = false;
    }
}


void dij(int sp) {
    d[sp] = 0;
    last[sp] = 0;
    for(int i = 0; i < n; ++i) {
        int minv = INTMAX, mini, minhap = INTMAX;
        float minavghep = INTMAX;
        for(int j = 0; j < n; ++j) {
            if(d[j] < minv && ! visit[j]) {
                mini = j;
                minhap = hapen[j];
                minavghep = hapen[j] / nodenum[j];
                minv = d[j];
            // }
            } else if(d[j] == minv && hapen[j] < minhap && ! visit[j]) {
                minavghep = hapen[j] / nodenum[j];
                minhap = hapen[j];
                mini = j;
                
            } else if(d[j] == minv && ! visit[j] && hapen[j] == minhap && hapen[j] / nodenum[j] < minavghep) {
                minavghep = hapen[j] / nodenum[j];
                mini = j;
                
            }
        }
        // cout << mini << endl;
        // for(int i = 0; i < n; ++i) {
        //     cout << shortestnum[i] << ' ';
        // }
        // cout << endl;
        // for(int i = 0; i < n; ++i) {
        //     cout << d[i] << ' ';
        // }
        // cout << endl;
        visit[mini] = true;
        for(int j = 0; j < n; ++j) {
            if(edge[mini][j] < INTMAX && !visit[j]) {
                if(d[mini] + edge[mini][j] < d[j]) {
                    d[j] = d[mini] + edge[mini][j];
                    hapen[j] = hapen[mini] + node[j];
                    nodenum[j] = nodenum[mini] + 1;
                    last[j] = mini;
                    shortestnum[j] = shortestnum[mini];
                    // cout << "111" << endl;
                // }
                } else if(d[mini] + edge[mini][j] == d[j]) {
                    shortestnum[j] = shortestnum[j] + shortestnum[mini];
                    if(hapen[j] < hapen[mini] + node[j]) {
                        hapen[j] = hapen[mini] + node[j];
                        nodenum[j] = nodenum[mini] + 1;
                        last[j] = mini;
                        // cout << "222" << endl;
                    } else if(hapen[j] == hapen[mini] + node[j] && nodenum[j] >  nodenum[mini] + 1) {
                        nodenum[j] = nodenum[mini] + 1;
                        last[j] = mini;
                        // cout << "333" << endl;
                    }
                }
            }
        }
    }
    int end = getIdx("ROM");
    stack <string> res;
    printf("%d %d %d %d\n", shortestnum[end], d[end], (int)hapen[end], (int)(hapen[end] / (nodenum[end])));
    while(1) {
        res.push(getStr(end));
        if(end == sp) {
            break;
        }
        end = last[end];
    }
    while(!res.empty()) {
        cout << res.top();
        if(res.size() != 1) {
            cout << "->";
        }
        res.pop();
    }
    cout << endl;

}

int main() {
    scanf("%d %d", &n, &m);
    cin >> start;
    for(int i = 0; i < n - 1; ++i) {
        string name;
        float h;
        cin >> name >> h;
        // cout << name << endl;
        str2idx.insert(make_pair(name, i));
        node[i] = h;
    }
    str2idx.insert(make_pair(start, n - 1));
    init();
    map <string, int> :: iterator it = str2idx.begin();
    // while(it != str2idx.end()) {
    //     cout << it->first <<' ' << it->second << endl;
    //     it++;
    // }
    // cout << n << ' ' << m << ' ' << start;
    for(int i = 0; i < m; ++i) {
        string a, b;
        int w;
        cin >> a >> b >> w;
        int ia = getIdx(a), ib = getIdx(b);
        // cout << ia << ' ' << ib << endl;
        edge[ia][ib] = w;
        edge[ib][ia] = w;
    }
    // for(int i = 0; i < n; ++i) {
    //     for(int j = 0; j < n; ++j) {
    //         cout << edge[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << getIdx(start) << endl;
    dij(getIdx(start));
}
