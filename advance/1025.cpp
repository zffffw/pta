#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
//存放该号数在哪个小组
map <string, int> localmap;

typedef vector <string> node[101];
//存放总的排名
node total;
//存放小组排名
node local[101];
int n;
int cmp(string a, string b) {
    return a < b;
}

int getRank(string num, int tnum) {
    int count = 1;
    for(int i = 100; i >= 0; --i) {
        if(local[tnum][i].size()) {
            for(int j = 0; j < local[tnum][i].size(); ++j) {
                if(local[tnum][i][j] == num) {
                    return count;
                }
            }
        }
        count += local[tnum][i].size();
    }

}

int main() {
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        int k;
        scanf("%d", &k);
        cnt += k;
        for(int j = 0; j < k; ++j) {
            char buf[128];
            int score;
            scanf("%s %d", buf, &score);
            string num = buf;
            localmap.insert(make_pair(num, i));
            total[score].push_back(num);
            local[i][score].push_back(num);
        }
    }

    printf("%d\n", cnt);
    int count = 1;
    for(int i = 100; i >= 0; --i) {
        if(total[i].size()) {
            sort(total[i].begin(), total[i].end(), cmp);
            for(int j = 0; j < total[i].size(); ++j) {
                string num = total[i][j];
                int idx = localmap[num];
                int teamRank = getRank(num, idx);
                cout << total[i][j] << ' ' << count << ' ' << idx << ' ' << teamRank << endl;
            }
        }
        count += total[i].size();
    }
}