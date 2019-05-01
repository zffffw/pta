#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    double sum = 0;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        double tmp;
        char buf1[1024] = {0};
        char buf2[1024] = {0};
        scanf("%s", buf1);
        sscanf(buf1, "%lf", &tmp);
        sprintf(buf2, "%.2lf", tmp);
        // printf("%s\n%s\n%lf\n\n", buf1, buf2, tmp);
        bool isNum = true;
        int len1 = strlen(buf1), len2 = strlen(buf2);
        for(int i = 0; i < len1; ++i) {
            if(buf1[i] != buf2[i]) {
                isNum = false;
                break;
            }
        }
        if(!isNum) 
            printf("ERROR: %s is not a legal number\n", buf1);
        else {
            
            if(tmp <= 1000 && tmp >= -1000) {
                sum += tmp;
                cnt++;
            } else
                printf("ERROR: %s is not a legal number\n", buf1);
        }
    }
    switch(cnt) {
        case 0:
        printf("The average of 0 numbers is Undefined\n");
        break;
        case 1:
        printf("The average of 1 number is %.2f\n", sum);
        break;
        default :
        printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
        break;
    }
}