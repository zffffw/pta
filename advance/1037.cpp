#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> coupon, product;
int n, m;
int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        coupon.push_back(tmp);
    }
    cin >> m;
    for(int i = 0; i < m; ++i) {
        int tmp;
        cin >> tmp;
        product.push_back(tmp);
    }
    sort(coupon.begin(), coupon.end());
    sort(product.begin(), product.end());
    
    vector <int> cg, cl, pg, pl;
    for(int i = 0; i < coupon.size(); ++i) {
        // cout << coupon[i] << ' ';
        if(coupon[i] > 0) {
            cg.push_back(coupon[i]);
        } else if (coupon[i] < 0) {
            cl.push_back(coupon[i]);
        }
    }
    // cout << endl;
    for(int i = 0; i < product.size(); ++i) {
        // cout << product[i] << ' ';
        if(product[i] > 0) {
            pg.push_back(product[i]);
        } else if (product[i] < 0) {
            pl.push_back(product[i]);
        }
    }
    // cout << endl;
    // vector <int> :: iterator it;
    // it = cg.begin();
    // while(it != cg.end()) {
    //     cout << *it << ' ';
    //     it++;
    // }
    // cout << endl;
    // it = cl.begin();
    // while(it != cl.end()) {
    //     cout << *it << ' ';
    //     it++;
    // }
    // cout << endl;
    // it = pg.begin();
    // while(it != pg.end()) {
    //     cout << *it << ' ';
    //     it++;
    // }
    // cout << endl;
    // it = pl.begin();
    // while(it != pl.end()) {
    //     cout << *it << ' ';
    //     it++;
    // }
    // cout << endl;

    int sum = 0;
    int k = 0, s = 0;
    while(k < cl.size() && s < pl.size()) {
        // cout << cl[k]*pl[s] << endl;
        sum += cl[k]*pl[s];
        k++;
        s++;
    }
    k = cg.size() - 1;
    s = pg.size() - 1;
    while(k >= 0 && s >= 0) {
        sum += cg[k]*pg[s];
        k--;
        s--;
    }
    cout << sum << endl;

    
}