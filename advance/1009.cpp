#include <iostream>
#include <iomanip>
using namespace std;
// 注意乘积之后指数取值的范围，和加的不一样

float po[2020];
int tempe[10];
float tempco[10];

int main() {
    int K1;
    cin >> K1;
    int e;
    float cof;
    for(int i = 0; i < K1; ++i) {
        cin >> e >> cof;
        tempe[i] = e;
        tempco[i] = cof;
    }
    int K2;
    cin >> K2;
    for(int i = 0; i < K2; ++i) {
        cin >> e >> cof;
        for(int j = 0; j < K1; ++j) {
            int res_e = tempe[j] + e;
            float res_co = tempco[j]*cof;
            po[res_e] += res_co;
        }
    }
    int count = 0;
    for(int i = 0; i <= 2000; ++i) {
        if(po[i] != 0) {
            count += 1;
        }
    }
    cout << count;
    for(int i = 2000; i >= 0; --i) {
        if(po[i] != 0){
            cout << ' ' << i << ' ' << setiosflags(ios::fixed) << setprecision(1) << po[i];
        }
    }

}