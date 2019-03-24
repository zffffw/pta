#include <iostream>
#include<iomanip>
using namespace std;

float game[3][3];
int maxWTL[3];
float maxOdd[3];
int main() {
    for(int i = 0; i < 3; ++i) {
        float tempmax = 0;
        int tempindex = 0;
        for(int j = 0; j < 3; ++j) {
            float a;
            cin >> a;
            if(j == 0) {
                a = a*0.65;
            }
            if(tempmax < a) {
                tempindex = j;
                tempmax = a;
            }
        }
        maxWTL[i] = tempindex;
        maxOdd[i] = tempmax;
    }
    float profit = (maxOdd[0]*maxOdd[1]*maxOdd[2] - 1)*2;
    for(int i = 0; i < 3; ++i) {
        if(maxWTL[i] == 0 ) {
            cout << "W ";
        } else if (maxWTL[i] == 1) {
            cout << "T ";
        } else {
            cout << "L ";
        }
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << profit << endl;
}