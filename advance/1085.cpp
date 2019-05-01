#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <long long> v;
int n;
long long p;

int binsearch(long long t) {
    int begin = 1;
    int end = v.size() - 1;
    while(begin <= end) {
        int mid = (begin + end) / 2;
        if(v[mid] <= t) {
            begin = mid + 1;
        } else if(v[mid] > t) {
            end = mid - 1;
        }
    }
    return begin;
}

int main() {
    scanf("%d %lld", &n, &p);
    for(int i = 0; i < n; ++i) {
        long long tmp;
        scanf("%lld", &tmp);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    long long maxn = v[v.size() - 1];
    int res = 0;
    for(int i = 0; i < n; ++i) {
        // int tmp = upper_bound(v.begin(), v.end(), v[i]*p) - v.begin();
        int tmp = binsearch(v[i]*p);
        // cout << tmp << endl;
        if(tmp - i > res) {
            res = tmp - i;
        }
    }
    printf("%d\n", res);
}