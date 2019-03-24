#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//超时
vector <int> student[200000];

int getIndex(const char *name) {
    return (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 + name[3] - '0';
}
int n, m;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m ; ++i) {
        int course, num;
        scanf("%d %d", &course, &num);
        for(int j = 0; j < num; ++j) {
            char s[5] = {};
            scanf("%s", s);
            student[getIndex(s)].push_back(course);

        }
    }
    for(int i = 0; i < n; ++i) {
        char s[5] = {};
        scanf("%s", s);
        int index = getIndex(s);
        sort(student[index].begin(), student[index].end());
        printf("%s %ld", s, student[index].size());
        for(int j = 0; j < student[index].size(); ++j) {
            printf(" %d", student[index][j]);
        }
        printf("\n");
    }
    return 0;
}