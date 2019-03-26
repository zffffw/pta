#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct info {
    string infomation[5];
} info;

map <string, info> m;
int n, testnum;
vector <string> res;

bool cmp(string a, string b) {
    return a < b;
}

int main() {
    cin >> n;
    getchar();
    for(int i = 0; i < n; ++i) {
        string num;
        char c;
        while((c = getchar()) != '\n') {
            num += c;
        }
        // printf("tstpoint1\n");
        info in;
        for(int j = 0; j < 5; ++j) {
            string tmp;
            char c;
            while((c = getchar()) != '\n') {
                tmp += c;
            }
            in.infomation[j] = tmp;
        }
        m.insert(make_pair(num, in));
    }
    cin >> testnum;
    getchar();
    for(int i = 0; i < testnum; ++i) {
        string num;
        res.clear();
        cin >> num;
        int idx = num[0] - '0' - 1;
        // cout << idx << endl;
        string tmp;
        char c;
        while((c = getchar()) != '\n') {
            tmp += c;
        }
        tmp.erase(0, 1);
        printf("%s %s\n", num.data(), tmp.data());
        map <string, info> :: iterator it;
        it = m.begin();
        while(it != m.end()) {
            if(idx != 2 && it->second.infomation[idx] == tmp)  {
                res.push_back(it->first);
            } else if(idx == 2 && it->second.infomation[idx].find(tmp, 0) <= it->second.infomation[idx].length()) {
                // printf("%lu\n", it->second.infomation[idx].find(tmp));
                res.push_back(it->first);
            }
            it++;
        }
        if(res.empty()) {
            printf("Not Found\n");
        } else {
            sort(res.begin(), res.end(), cmp);
            for(int k = 0; k < res.size(); ++k) {
                printf("%s\n", res[k].data());
            }
        }
    }
}