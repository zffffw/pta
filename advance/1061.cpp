#include <iostream>
#include <string.h>
using namespace std;

char buf1[128] = {0};
char buf2[128] = {0};
char buf3[128] = {0};
char buf4[128] = {0};
char day[7][10] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main() {
    scanf("%s\n%s\n%s\n%s", buf1, buf2, buf3, buf4);
    int cnt = 0;
    int posi = -1;
    for(int i = 0; i < strlen(buf1); ++i) {
        if(buf1[i] >= 'A' && buf1[i] <= 'G') {
            if(buf1[i] == buf2[i]) {
                posi = i;
                printf("%s ", day[buf1[i] - 'A']);
                break;
            }
        }
    }
    for(int i = posi + 1; i < strlen(buf1); ++i) {
        if((buf1[i] >= 'A' && buf1[i] <= 'N') || (buf1[i] >= '0' && buf1[i] <= '9')) {
            if(buf1[i] == buf2[i]) {
                // s[cnt++] = bu;
                printf("%02d:", buf1[i] >= 'A' ? buf1[i] - 'A' + 10 : buf1[i] - '0');
                break;
            }
        }
    }
    for(int i = 0; i < strlen(buf3); ++i) {
        if((buf3[i] >= 'A' && buf3[i] <= 'Z') || (buf3[i] >= 'a' && buf3[i] <= 'z')) {
            if(buf3[i] == buf4[i]) {
                printf("%02d\n", i);
                break;
            }
        }
    }
    // cout << s[0] << ' ' << s[1] << ' ' << s[2] << endl;
    // printf("%s %02d:%02d\n", day[s[0] - 'A'], s[1] > '9' ? s[1] - 'A' + 10 : s[1] - '0', pos);
}