#include <iostream>
#include <string>
using namespace std;

int n;
bool twodec(string s) {
    int cnt = 0;
    int cntbefore = 0;
    bool flag = false;
    if((s[0] == '0' && s[1] != '.') || (s[0] == '-' && s[1] == '0' && s[2] != '.')) {
        return false;
    }
    for(string :: iterator it = s.begin(); it != s.end(); ++it) {
        if(!flag && *it >= '0' && *it <= '9')
            cntbefore ++;
        if(*it == '.')
            flag = true;
        if(flag && *it >= '0' && *it <= '9')
            cnt ++;
    }
    if(cntbefore > 4)
        return false;
    
    if(cnt < 2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    scanf("%d\n", &n);
    int cnt = 0;
    char c;
    double num[105] = {0};
    string tmp;
    bool isNum = true;
    int cntpoint = 0;
    while((c = getchar())) {
        if(isNum && c == '-' && tmp.size() == 0 ) {
            tmp += c;
        } else if(isNum && c == '.' && (tmp[tmp.size() - 1] >= '0' && tmp[tmp.size() - 1] <= '9' && !cntpoint)) {
            tmp += c;
            cntpoint ++;
        } else if(isNum && c >= '0' && c <= '9' && twodec(tmp)) {
            tmp += c;
        } else if(c == ' ' || c =='\n') {

            if(isNum) {
                double number = atof(tmp.data());
                if(number <= 1000 && number >= -1000) {
                    num[cnt++] = number;
                } else {
                    printf("ERROR: %s is not a legal number\n", tmp.data());
                }
            }
            if(!isNum) {
                printf("ERROR: %s is not a legal number\n", tmp.data());
            }
            tmp.clear();
            if(c == '\n')
                break;
            isNum = true;
            cntpoint = 0;
        } else {
            tmp += c;
            isNum = false;
        }
    }
    double mean = 0;
    for(int i = 0; i < cnt; ++i) {
        mean += num[i];
    }
    mean = cnt == 0 ? 0 : mean / cnt;
    if(!cnt)
        printf("The average of 0 numbers is Undefined\n");
    else if (cnt == 1)
        printf("The average of 1 number is %.2f\n", mean);
    else
        printf("The average of %d numbers is %.2f\n", cnt, mean);
}