#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct node {
    string idx;
    int a;
    int b;
    int s;
    bool operator < (const node &A) const {
        if(s != A.s)
            return s > A.s;
        else if(a != A.a)
            return a > A.a;
        else
            return idx < A.idx;
    }
} node;

vector <node> v[4];

int n, L, H;

int main() {
    scanf("%d %d %d", &n, &L, &H);
    int total = 0;
    for(int i = 0; i < n; ++i) {
        char buf[128];
        int a, b;
        scanf("%s %d %d", buf, &a, &b);
        string idx = buf;
        node tmp = {buf, a, b, a + b};
        if(a >= H && b >= H) {  
            v[0].push_back(tmp);
            total ++;
        } else if(a >= H && b >= L) {
            v[1].push_back(tmp);
            total ++;
        } else if(a >= b && a < H && b < H && a >= L && b >= L) {
            v[2].push_back(tmp);
            total ++;
        } else if(a >= L && b >= L) {
            v[3].push_back(tmp);
            total ++;
        }
    }
    printf("%d\n", total);
    for(int i = 0; i < 4; ++i) {
        sort(v[i].begin(), v[i].end());
        for(int j = 0; j < v[i].size(); ++j) {
            printf("%s %d %d\n", v[i][j].idx.data(), v[i][j].a, v[i][j].b);
        }
    }
}