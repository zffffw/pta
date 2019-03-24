#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct table {
    string num;
    string st;
    string et;
} table;

vector <table> v;
int cmp1(table a, table b) {
    return a.st < b.st;
}
int cmp2(table a, table b) {
    return a.et > b.et;
}
int n;
int main() {
    cin >> n;

    for(int i = 0; i < n; ++i) {
        table tmp;
        cin >> tmp.num >> tmp.st >> tmp.et;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp1);
    cout << v[0].num << ' ';
    sort(v.begin(), v.end(), cmp2);
    cout << v[0].num << endl;
}