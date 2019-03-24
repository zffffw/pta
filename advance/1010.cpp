
// got 19
// radix can larger than 36
// 二分法
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
long long int num2Dec(string s, int radix_);
string num1, num2;
string procNum;
string nonProcNum;
int tag, radix;

long long int numDec;

void tryAllPoss() {
    string::iterator ite;
    ite = procNum.begin();
    char maxch = 0;
    for(int i = 0; i < procNum.size(); ++i) {
        if(*ite > maxch) {
            maxch = *ite;
        }
        ite++;
    }
    int minradix = 1;
    if('0' < maxch && maxch <= '9') {
        minradix = maxch - '0' + 1;
    } else if (maxch >= 'a'){
        minradix = maxch - 'a' + 11;
    }
    // cout << minradix << ' ' << maxch << endl;
    int i = 0;
    int find = 0;
    long long int low = minradix;
    long long int high = max(low, numDec);
    long long int mid;
    // cout << high << endl;
    while(low <= high) {
        mid = (low + high)/2;
        // cout << low << ' ' << mid << ' ' << high << endl;
        long long int tmp = num2Dec(procNum, mid);
        // cout << tmp << endl;
        if (tmp < numDec && tmp >= 0) {
            low = mid + 1;
        } else if (tmp > numDec || tmp < 0 ) {
            high = mid - 1;
        } else if (tmp == numDec) {
            cout << mid << endl;
            find = 1;
            break;
        }
    }
    // for(i = minradix;; ++i) {
    //     // cout << num2Dec(procNum, i) << " i:" << i << endl;
    //     if(num2Dec(procNum, i) == numDec) {
    //         cout << i << endl;
    //         find = 1;
    //         break;
    //     }
    //     if(num2Dec(procNum, i) > numDec) {
    //         break;
    //     }
    //     // cout << num2Dec(num2, i) << ' ' << i << endl;
    // }
    if(!find) {
        cout << "Impossible" << endl;
    }
}

long long int num2Dec(string s, int radix_) {
    string::iterator ite;
    ite = s.begin();
    long long int res = 0;
    for(int i = s.size() - 1; i >= 0; --i) {
        int tmpnum = *ite >= 'a' ? *ite - 'a' + 10 : *ite - '0';
        res += (tmpnum)*pow(radix_, i);
        ite++;
    }
    return res;
}

int main() {
    cin >> num1 >> num2 >> tag >> radix;
    if (tag == 1) {
        procNum = num2;
        nonProcNum = num1;
    } else {
        procNum = num1;
        nonProcNum = num2;
    }
    numDec = num2Dec(nonProcNum, radix);
    // cout << numDec << endl;
    tryAllPoss();
}