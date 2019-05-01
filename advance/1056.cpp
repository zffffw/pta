#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct node {
    int idx;
    int rank;
    bool operator < (const node &A) const {
        return rank > A.rank;
    }
}node;
int n, k;

int main() {
    int wi[1001];
    vector <int> arr;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &wi[i]);
    }
    for(int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        arr.push_back(tmp);
    }
    // sort(arr.begin(), arr.end());
    // for(int i = 0; i < n; ++i) {
    //     cout << arr[i] << ' ';
    // }
    // cout <<"*****" << endl;
    vector <int> tmpres = arr;
    vector <node> res;
    int cntRank = 0;
    int rank[10001] = {0};
    while(1) {
        // sort(tmpres.begin(), tmpres.end());
        if(tmpres.size() == 1) {
            node tmpnode = {tmpres[0], cntRank};
            res.push_back(tmpnode);
            break;
        }
        int step = tmpres.size() / k;
        vector <int> arrtmp = tmpres;
        tmpres.clear();
        int totalsize = arrtmp.size();
        // cout << arrtmp.size() << ' ' << tmpres.size() << endl;
        for(int i = 0; i <= step; ++i) {
            int tmpmax = -1, tmpi;
            int end = i == step ? totalsize : i * k + k;
            // cout << "st:" << end << endl;
            for(int j = i*k; j < end; ++j) {
                if(wi[arrtmp[j]] > tmpmax) {
                    tmpmax = wi[arrtmp[j]];
                    tmpi = j;
                }
            }
            if(end != i*k)
                tmpres.push_back(arrtmp[tmpi]);
            for(int j = i*k; j < end; ++j) {
                if(j != tmpi) {
                    node tmpnode = {arrtmp[j], cntRank};
                    // cout << wi[arrtmp[j]] << endl;
                    res.push_back(tmpnode);
                }
            }
        }
        // cout << tmpres.size() << ' ' << res.size() << endl;
        getchar();
        cntRank ++;
        
    }
    sort(res.begin(), res.end());
    int last = res[0].rank;
    int cnt = 1;
    for(int i = 0; i < n; i++) {
        // cout << res[i].rank << ' ' << res[i].idx  << endl;
        if(last != res[i].rank) {
            cnt = i + 1;
            last = res[i].rank;
        }
        rank[res[i].idx] = cnt;
    }
    for(int i = 0; i < n; ++i) {
        if(i != 0)
            putchar(' ');
        printf("%d", rank[i]);
    }
    putchar('\n');
}