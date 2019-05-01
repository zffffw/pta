#include <iostream>
using namespace std;
long long int num;
int main() {
    cin >> num;
    int k = 2;
    long long int cpn = num;
    cout << cpn << '=';
    if(cpn == 1) {
        cout << 1 << endl;
        return 0;
    }
    int flag = 1;
    while(num > 1) {
        int cnt = 0;
        // cout << k << endl;
        while(num % k == 0) {
            cnt ++;
            num /= k;
        }
        // if (cnt == 1) {
        //     if(!flag) {
        //         putchar('*');
        //     }
        //     printf("%d", k);
        //     flag = 0;
        // } else if (cnt != 0){
        //     if(!flag) {
        //         putchar('*');
        //     }
        //     printf("%d^%d", k, cnt);
        //     flag = 0;
        // }
        k++;
    }
    cout << endl;
    return 0;
}