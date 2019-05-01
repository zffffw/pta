#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
//并查集
using namespace std;
typedef struct node {
    string name;
    int val;
    bool operator < (const node &A) const {
        return name < A.name;
    }
} node;
map <string, int> name2idx;
map <int, string> idx2name;
int people[2001];
int fa[2001];
int n, k;
vector <int> que[2001];
int maxname[2001];
int maxval[2001];
int maxvaltotal[2001];
int getIdx(string name) {
    map <string, int> :: iterator it = name2idx.find(name);
    if(it == name2idx.end()) {
        name2idx.insert(make_pair(name, name2idx.size()));
        return name2idx.size() - 1;
    } else {
        return it->second;
    }
    return -1;
}

string getName(int idx, string name="") {
    map <int, string> :: iterator it = idx2name.find(idx);
    if(it == idx2name.end()) {
        idx2name.insert(make_pair(idx, name));
    } else {
        return it->second;
    }
    return "";
}

int find(int x) {
    if(x == fa[x]) {
        return x;
    } 
    int tmp = fa[x];
    fa[x] = find(fa[x]);
    return fa[x];
}
void init() {
    for(int i = 0; i <= 2000; ++i) {
        fa[i] = i;
        people[i] = 0;
        maxname[i] = 0;
        maxvaltotal[i] = 0;
        maxval[i] = 0;
    }
}

int main() {
    scanf("%d %d", &n, &k);
    init();
    
    
    for(int i = 0; i < n; ++i) {
        int x, y, w;
        string name1, name2;
        cin >> name1 >> name2 >> w;
        x = getIdx(name1);
        y = getIdx(name2);
        getName(x, name1);
        getName(y, name2);
        people[x] += w;
        people[y] += w;
        int fx = find(x);
        int fy = find(y);
        if(fx != fy) {
            fa[fx] = fy;
        }
        // find(x);
        // find(y);
        maxvaltotal[find(x)] += w;
    }
    int maxvalto[2001] = {0};
    for(int i = 0; i < n; ++i) {
        int tmp = find(i);
        que[tmp].push_back(i);
        maxvalto[tmp] += maxvaltotal[i];
        if(maxval[tmp] < people[i]) {
            maxval[tmp] = people[i];
            maxname[tmp] = i;
        }
    }
    // for(int i = 0; i < n; ++i) {
    //     cout << maxval[i] << ' ';
    // }
    // cout << endl;
    // for(int i = 0; i < n; ++i) {
    //     cout << maxname[i] << ' ';
    // }
    // cout << endl;
    // for(int i = 0; i < n; ++i) {
    //     cout << maxvalto[i] << ' ';
    // }
    // cout << endl;
    // for( map <string, int> :: iterator it = name2idx.begin(); it != name2idx.end(); it ++) {
    //     cout << it->first << ' ' << it->second << endl;
    // }
    vector <node> res;
    for(int i = 0; i < n; ++i) {
        if(que[i].size() > 2) {
            if(maxvalto[i] > k) {
                node t = {getName(maxname[i]), que[i].size()};
                res.push_back(t);
            }
        }
    }
    cout << res.size() << endl;
    sort(res.begin(), res.end());
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i].name << ' ' << res[i].val << endl;
    }
    // cout << endl;
    // for( map <int, string> :: iterator it = idx2name.begin(); it != idx2name.end(); it ++) {
    //     cout << it->first << ' ' << it->second << endl;
    // }
    // cout << find(0) << endl;
    // for(int i = 0; i < n; ++i) {
    //     cout << fa[i] << ' ';
    // }
    // cout << endl;
    // for(int i = 0; i < n; ++i) {
    //     cout << people[i] << ' ';
    // }
    // cout << endl;
    
}



