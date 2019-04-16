#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef struct node {
    int id;
    int level;
}node;

vector <int> v[1001];
int n, m;
int cnt = 0;
int visit[1001];

void bfs(int start) {    
    queue <node> q;
    node tmp = {start, 0};
    visit[start] = 1;
    q.push(tmp);
    while(!q.empty()) {
        node cur = q.front();
        q.pop();
        for(int i = 0; i < v[cur.id].size(); ++i) {
            int next = v[cur.id][i];
            if(!visit[next]) {
                node tmp = {next, cur.level + 1};
                if(tmp.level <= m ) {
                    visit[next] = 1;
                    cnt++;
                    q.push(tmp);
                }
                
            }
        }
    }

}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; ++j) {
            int p;
            scanf("%d", &p);
            v[p].push_back(i);
        }
    }
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; ++i) {
        cnt = 0;
        int p;
        for(int i = 1; i <= n; ++i) {
            visit[i] = 0;
        }
        scanf("%d", &p);
        bfs(p);
        printf("%d\n", cnt);
    }
}