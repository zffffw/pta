//注意层级不能在输入的时候确定
//只需要知道是否有孩子即可，用一个结构体数组存放，然后变量所有节点，若是叶子，则该层级叶子节点加1，存放在depth数组中
#include <iostream>
using namespace std;

typedef struct {
    int kids[101];
    int depth;
} FTree;

int N, M;
FTree family[101];
int depth[101];

void find() {
    int maxdep = 0;
    for(int i = 1; i <= 100; ++i) {
        bool hasKid = false;
        if(maxdep < family[i].depth) {
            maxdep = family[i].depth;
        }
        for(int j = 1; j <= 100; ++j) {
            if(family[i].kids[j]) {
                hasKid = true;
                break;
            }
        }
        if(!hasKid) {
            depth[family[i].depth] += 1;
        }
    }
    for(int i = 1; i < maxdep; ++i) {
        cout << depth[i] << ' ';
    }
    cout << depth[maxdep] << endl;
}

int main() {
    
    cin >> N >> M;
    family[1].depth = 1;
    for(int i = 0; i < M; ++i) {
        int ID, K;
        cin >> ID >> K;
        for(int j = 0; j < K; ++j) {
            int IDk;
            cin >> IDk;
            // cout << ID << ' ' << IDk << endl;
            family[ID].kids[IDk] = 1;
            // family[IDk].depth = family[ID].depth + 1;
        }
    }
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(family[i].kids[j]) {
                family[j].depth = family[i].depth + 1;
            }
        }
    }
    find();
    

}