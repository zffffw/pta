#include <iostream>
#include <string>
using namespace std;
string number;

char outputAscii[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};


void output(int num, int flag) {
    if(num != 0) {
        output(num/10, 0);
        int tmp = num % 10;
        if (flag) {
            cout << outputAscii[tmp];
        } else {
            cout << outputAscii[tmp] << ' ';
        }
        return ;
    } else {
        return ;
    }
}

int main() {
    cin >> number;
    int sum = 0;
    for(int i = 0; i < number.size(); ++i) {
        sum += number[i] - '0';
    }
    if (sum == 0) {
        cout << "zero" << endl;
    } else {
        output(sum, 1);
    }
}
