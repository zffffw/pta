#include <iostream>
#include <math.h>
using namespace std;
long long int n;

int main() {
    cin >> n;
    int cnt = 1;
    int res = 0;
    int tmp = n;
    int digit = log10(n);
    digit ++;
    // cout << digit << endl;
    for(int i = 0; i < digit; ++i) {
        
        int t = tmp % 10;
        int b = tmp / 10;
        if(i == digit - 1) {
            if(t == 1) {
                res += n % cnt + 1;
            } else {
                res += cnt;
            }
            break;
        }
        if(t > 1) {
            b++;
            res += b * cnt;
        } else if (t == 1){
            res += b * cnt + n % cnt + 1;
        } else {
            res += b * cnt;
        }
        
        // getchar();
        // cout << i << ' ' << b * cnt << endl;
        
        tmp /= 10;
        cnt *= 10;
    }
    cout << res << endl;
    
}