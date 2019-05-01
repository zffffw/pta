#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct node {
    int idx;
    int ga;
    int gb;
    int avgg;
    int choice[6];
    int rank;
    bool operator < (const node &A) const {
        if(avgg != A.avgg) {
            return avgg > A.avgg;
        } else {
            return ga > A.ga;
        }
    }
} node;

vector <node> v;
vector <int> res[105];
int N, M, K;
int places[105] = {0};
int lastRank[105] = {0};
int main() {
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < M; ++i) {
        scanf("%d", &places[i]);
    }
    for(int i = 0; i < N; ++i) {
        int a, b, s[6];
        scanf("%d %d ", &a, &b);
        node tmp = {i, a, b, (a + b) / 2, {-1}, 0};
        
        for(int j = 0; j < K; ++j) {
            scanf("%d", &tmp.choice[j]);
        }
        // for(int j = 0; j < K; ++j) {
        //     cout << tmp.choice[j] << ' ';
        // }
        // cout << endl;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    
    int rank = 1;
    int lastavgg = v[0].avgg, lastag = v[0].ga;
    for(int i = 0; i < v.size(); ++i) {
        if(v[i].avgg != lastavgg || (v[i].avgg == lastavgg && v[i].ga != lastag)) {
            rank = i + 1;
            lastavgg = v[i].avgg;
            lastag = v[i].ga;
        }
        v[i].rank = rank;
    }
    // for(vector <node> :: iterator it = v.begin(); it != v.end(); ++it) {
    //     cout << it->idx <<' ' << it->ga << ' ' << it->gb << ' ' << it->rank << ' ' << it->choice[0] << endl;
    // }

    for(vector <node> :: iterator it = v.begin(); it != v.end(); ++it) {
        // cout << it->ga << ' ' << it->gb << ' ' << it->choice[0] << endl;
        for(int i = 0; i < K; ++i) {
            int choice = it->choice[i];
            if(places[choice] > 0 || (places[choice] <= 0 && it->rank == lastRank[choice])) {
                res[choice].push_back(it->idx);
                places[choice] --;
                lastRank[choice] = it->rank;
                break;
            }
        }
    }
    for(int i = 0; i < M; ++i) {
        sort(res[i].begin(), res[i].end());
        for(int j = 0; j < res[i].size(); ++j) {
            if(j != 0)
                putchar(' ');
            printf("%d", res[i][j]);
        }
        putchar('\n');
    }

}