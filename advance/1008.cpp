#include <iostream>

using namespace std;
int number[101];
int numberMinus[101];
int K;
int totalTime;
int main() {
    cin >> K;
    // totalTime += 5*K;
    for(int i = 1; i <= K; ++i) {
        cin >> number[i];
        numberMinus[i] = number[i] -  number[i - 1];
    }
    for(int i = 1; i <= K; ++i) {
        // cout << number[i] << ' ' << numberMinus[i] << endl;
        // if(number[i] == number[i - 1])
        //     continue;
        totalTime += numberMinus[i] >= 0? 6*numberMinus[i] + 5: -4*numberMinus[i] + 5;
        
    }

    cout << totalTime << endl;
}