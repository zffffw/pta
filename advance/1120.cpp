#include <iostream>
using namespace std;

int n;
int flag[1000] = {0};

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        int cnt = 0;
        while(tmp) {
            cnt += tmp % 10;
            tmp /= 10;
        }
        flag[cnt] = 1;
    }
    int cnt = 0;

    for(int i = 0; i < 200; ++i) {
        if(flag[i]) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    bool output = false;
    for(int i = 0; i < 200; ++i) {
        if(flag[i]) {
            if(output)
                putchar(' ');
            printf("%d", i);
            output = true;
        }
    }
}