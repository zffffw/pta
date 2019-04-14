#include <iostream>
using namespace std;
int num[1000001];
int pos[1000001];
int n;
int main() {
    scanf("%d", &n);
    int zeropos;
    for(int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        num[i] = tmp;
        pos[tmp] = i;
        if(tmp == 0) {
            zeropos = i;
        }
    }
    int cur = 0;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        while(num[0] != 0) {
            int p = pos[zeropos];
            num[p] = 0;
            num[zeropos] = zeropos;
            pos[0] = p;
            pos[zeropos] = zeropos;
            zeropos = p;
            cnt ++;
        }
        if(i != num[i]) {
            int p = pos[i];
            num[p] = 0;
            num[0] = i;
            pos[0] = p;
            pos[i] = 0;
            zeropos = p;
            cnt++;
        }
    }
    cout << cnt << endl;
}