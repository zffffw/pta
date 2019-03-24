#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

queue <int> a, b;
int m, n;

int main() {
    cin >> m;
    for(int i = 0; i < m; ++i) {
        long long int tmp;
        scanf("%lld", &tmp);
        tmp = min((long long )INT_MAX, tmp);
        a.push(tmp);
    }
    a.push(INT_MAX);
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        long long int tmp;
        scanf("%lld", &tmp);
        tmp = min((long long )INT_MAX, tmp);
        b.push(tmp);
        if(cnt == (n + m - 1)/2) {
            cout << min(a.front(), b.front()) << endl;
            return 0;
        }
        if (a.front() < b.front()) {
            a.pop();
        } else {
            b.pop();
        }
        cnt ++;
        // cout << cnt << endl;
    }
    b.push(INT_MAX);
    for(;cnt < (n + m - 1)/2;) {
        if (a.front() < b.front()) {
            a.pop();
        } else {
            b.pop();
        }
        cnt ++;
    }
    cout << min(a.front(), b.front()) << endl;
}