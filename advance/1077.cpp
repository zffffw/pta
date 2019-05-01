#include <iostream>
#include <string>
using namespace std;
int n;

int main() {
    string s[101];
    scanf("%d\n", &n);
    int minsize = 1000000;
    for(int i = 0; i < n; ++i) {
        char c;
        while((c = getchar()) != '\n') {
            s[i] += c;
        }
        if(s[i].size() < minsize) {
            minsize = s[i].size();
        }
    }
    string res;
    for(int i = 0; i < minsize; ++i) {
        char c = s[0][s[0].size() - 1 - i];
        bool flag = true;
        for(int j = 1; j < n; ++j) {
            if(c != s[j][s[j].size() - 1 - i]) {
                flag = false;
                break;
            }
        }
        if(!flag) {
            break;
        }
        res += c;
    }
    if(res.size())
        for(int i = res.size() - 1; i >= 0; --i) {
            putchar(res[i]);
        }
    else
        printf("nai");
    putchar('\n');
}