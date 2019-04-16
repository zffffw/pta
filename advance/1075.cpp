#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef struct node {
    int id;
    int score[6];
    int totalScore;
    int prefect;
} node;

map <int, node> ma;
vector <node> v;
int N, K, m;
int full[6];

int cmp(node a, node b) {
    if(a.totalScore != b.totalScore) {
        return a.totalScore > b.totalScore;
    } else if (a.prefect != b.prefect) {
        return a.prefect > b.prefect;
    } else {
        return a.id < b.id;
    }
}

int main() {
    map <int, node> :: iterator it;
    scanf("%d %d %d", &N, &K, &m);
    for(int i = 1; i <= K; ++i) {
        scanf("%d", &full[i]);
    }
    for(int i = 0; i < m; ++i) {
        int id;
        int probId;
        int score;
        scanf("%d %d %d", &id, &probId, &score);
        it = ma.find(id);
        if(it == ma.end()) {
            node tmp = {id, {0}, 0, 0};
            for(int k = 1; k <= K; ++k) {
                tmp.score[k] = -2;
            }
            tmp.score[probId] = score;
            if(score != -1)
                tmp.totalScore += score;
            ma.insert(make_pair(id, tmp));
        } else {
            if(it->second.score[probId] == -2) {
                it->second.score[probId] = score;
                if(score != -1)
                    it->second.totalScore += score;
            } else if(it->second.score[probId] < score) {
                if(it->second.score[probId] == -1)
                    it->second.score[probId] = 0;
                it->second.totalScore = it->second.totalScore - it->second.score[probId] + score;
                it->second.score[probId] = score;
            }
        }
    }
    it = ma.begin();
    while(it != ma.end()) {
        int cnt = 0;
        int flag = false;
        for(int i = 1; i <= K; ++i) {
            if(it->second.score[i] == full[i]) {
                it->second.prefect ++;
            } 
            if(it->second.score[i] != -1 && it->second.score[i] != -2) {
                flag = true;
            }
        }
        if(flag)
            v.push_back(it->second);
        it++;
    }
    sort(v.begin(), v.end(), cmp);
    int rank = 1;

    int last ;
    if(v.size()) {
        last = v[0].totalScore;
    }
    for(int i = 0; i < v.size(); ++i) {
        if(v[i].totalScore != last) {
            rank = i + 1;
            last = v[i].totalScore;
        }
        printf("%d %05d %d", rank, v[i].id, v[i].totalScore);
        for(int j = 1; j <= K; ++j) {
            if(v[i].score[j] == -2) {
                printf(" -");
            }else {
                if(v[i].score[j] == -1) 
                    v[i].score[j] = 0;
                printf(" %d", v[i].score[j]);
            }
        }
        putchar('\n');
    }
}