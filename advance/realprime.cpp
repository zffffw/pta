#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;
//注意1，否则有一个测试的过不去


int reverseNum(int num) {
    int sum = 0;
    int i = 1;
    int dight = 0;
    int tmp = num;
    while(tmp != 0) {
        i *= 10;
        tmp /=10;
    }
    i /= 10;
    while(num != 0) {
        sum += (num % 10)*i;
        i /= 10;
        num /= 10;
    }

    return sum;
}

bool isPrime(int num) {
    if(num <= 1) {
        return false;
    }
    if(num == 2 || num == 3) {
        return true;
    }
    for(int i = 2 ; i < sqrt(num) + 1; ++i) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int minn;
    int maxn;
    cin >> minn >> maxn;
    int flag = 0;
    for(int i = minn; i <= maxn; ++i) {
        int temp = reverseNum(i);
        if(isPrime(temp) && isPrime(i)) {
            if(flag == 0) {
                flag = 1;
                printf("%d", i);
            } else {
                printf(",%d", i);
            }
        }
    }
    printf("\n");
    return 0;
}