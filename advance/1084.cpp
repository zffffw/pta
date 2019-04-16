#include <iostream>
#include <string>
using namespace std;
int main() {
    char s[1000] = {0};
    char c;
    int fl[256] = {0};
    scanf("%s\n", s);
    while((c = getchar()) != '\n') {
        fl[c] = 1;
    }
    int flag[256] = {0};
    int i = -1;
    while(s[++i]) {
        c = s[i] >= 'a' && s[i] <= 'z' ? s[i] - 'a' + 'A' : s[i];
        if(!fl[s[i]] && !flag[c]) {
            putchar(c);
            flag[c] = 1;
        }
    }
    putchar('\n');
}