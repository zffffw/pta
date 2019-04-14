#include <iostream>
using namespace std;
char s[10001];
int tmp[256];
int main() {
    char c;
    int len = 0;
    while((c = getchar()) != '\n') {
        s[len++] = c;
    }
    while((c = getchar()) != '\n') {
        tmp[c] = 1;
    }
    for(int i = 0; i < len; ++i) {
        if(!tmp[s[i]])
            putchar(s[i]);
    }
    putchar('\n');
}