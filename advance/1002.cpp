#include <iostream>
#include<iomanip>
using namespace std;

float e[1010];

int main() {
    int K;
    for(int i = 0 ; i < 2; ++i) {
        int tempe;
        float tempco;
        cin >> K;
        for(int j = 0; j < K; ++j) {
            cin >> tempe >> tempco;
            e[tempe] += tempco;
        }
    }
    int count = 0;
    for(int i = 0; i <= 1000; ++i) {
        if(e[i] != 0) {
            count += 1;
        }
    }
    cout << count;
    for(int i = 0; i >= 0; --i) {
        if(e[i] != 0) {
            cout << ' ' << i << ' ' << setiosflags(ios::fixed) << setprecision(1) << e[i];
        }
    }
}