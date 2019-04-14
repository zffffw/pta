#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector <long int> vector2d;
vector <int> v[100];
vector <vector2d> res;
long int weight[100];
int n, m, target;
vector <long int> path;
int visit[100];

int cmp(vector2d a, vector2d b) {
    int minn = min(a.size(), b.size());
    for(int i = 0;i < minn; ++i) {
        if(a[i] != b[i]) {
            return a[i] > b[i];
        }
    }
    return false;
}

int sumV() {
    long int res = 0;
    for(int i = 0; i < path.size(); ++i) {
        res += path[i];
    }
    return res;
}

void dfs(int curv) {
    
    if(sumV() == target && v[curv].size() == 0) {
        res.push_back(path);
        return ;
    }
    for(int i = 0; i < v[curv].size(); ++i) {
        int next = v[curv][i];
        if(!visit[next]) {
            visit[next] = 1;
            path.push_back(weight[next]);
            dfs(next);
            visit[next] = 0;
            path.pop_back();
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &target);
    for(int i = 0; i < n; ++i) {
        scanf("%ld", &weight[i]);
    }
    for(int i = 0; i < m; ++i) {
        int tmpv;
        int k;
        scanf("%d %d", &tmpv, &k);
        for(int j = 0; j < k ;++j) {
            int tmp;
            scanf("%d", &tmp);
            v[tmpv].push_back(tmp);
        }
    }
    visit[0] = 1;
    path.push_back(weight[0]);
    dfs(0);
    sort(res.begin(), res.end(), cmp);
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i][0] ;
        for(int j = 1; j < res[i].size(); ++j) {
            cout  << ' ' << res[i][j];
        }
        cout << endl;
    }
}