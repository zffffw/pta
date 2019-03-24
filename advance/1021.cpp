#include <iostream>
#include <vector>
using namespace std;

//判断是否连通，如果连通则一定是树，然后任意找一个点dfs，获取最深的点，然后再从那个点做一次dfs，保存下每个结点的深度，然后就是结果。

vector <int> map[10002]; //结点链表
int maxNodeNum;
int visit[10002];
int maxdepth = 0;
int maxi = 0;
int height[10002];
void dfs(int node, int depth) {
    if(!visit[node]) {
        visit[node] = 1;
        if (height[node] < depth) {
            height[node] = depth;
        }
        if(maxdepth < depth) {
            maxi = node;
            maxdepth = depth;
        }
        vector <int>::iterator ite;
        ite = map[node].begin();
        for(;ite != map[node].end(); ++ite) {
            dfs(*ite, depth + 1);
        }
    }

}

void dfsSearch() {
    int compo = 0;
    for(int i = 1; i <= maxNodeNum; ++i) {
        if(!visit[i]) {
            compo ++;
            dfs(i, 1);
        }
    }
    if(compo > 1) {
        printf("Error: %d components\n", compo);
    } else {
        // cout << "t" << maxi << ' ' << maxdepth << endl;
        int temp = maxi;
        for(int i = 1; i <= maxNodeNum; ++i) {
            visit[i] = 0;
        }
        dfs(temp, 1);
        // for(int i = 1; i <= maxNodeNum; ++i) {
        //     cout << height[i] << ' ';
        // }
        // cout << endl;
        int next = 0;
        for(int i = 1; i <= maxNodeNum; ++i) {
            if(height[i] == maxdepth) {
                next = i;
                // printf("%d\n", i);
            }
        }
        for(int i = 1; i <= maxNodeNum; ++i) {
            visit[i] = 0;
        }
        dfs(next, 1);
        for(int i = 1; i <= maxNodeNum; ++i) {
            if(height[i] == maxdepth) {
                // next = i;
                printf("%d\n", i);
            }
        }
    }
    // putchar('\n');

}

int main() {
    scanf("%d", &maxNodeNum);
    for(int i = 0; i < maxNodeNum - 1; ++i) {
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    dfsSearch();
}