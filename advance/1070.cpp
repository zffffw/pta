#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct node {
    float supply;
    float price;
    float c;
} node;

int n, m;
vector <node> v;

int cmp(node a, node b) {
    if(a.c != b.c) {
        return a.c > b.c;
    }
    return a.supply > b.supply;
}

int main() {
    scanf("%d %d", &n, &m);
    float sup[1010];
    float pri[1010];
    for(int i = 0; i < n; ++i) {
        scanf("%f", &sup[i]);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%f", &pri[i]);
    }
    for(int i = 0; i < n; ++i) {
        float c = pri[i] / sup[i];
        node tmp = {sup[i], pri[i], c};
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);
    // for(int i = 0; i < v.size(); ++i) {
    //     cout << v[i].price << ' ' << v[i].supply << endl;
    // }
    float curs = 0;
    float total = 0;
    for(int i = 0; i < v.size(); ++i) {
        if(curs + v[i].supply < m) {
            curs += v[i].supply;
            total += v[i].price;
        } else {
            total += v[i].price*(m - curs)/v[i].supply;
            curs = m;
            break;
        }
    }
    printf("%.2f\n", total);
}