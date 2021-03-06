#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct node {
    double price;
    int di;
} node;

int tank, dis, waste, n;
vector <node> v;
int cmp(node a, node b) {
    return a.di < b.di;
}

//贪心策略，如果前面的可到达的加油站没有比当前的加油站价格低的，应该在现在就加尽可能多的油(如果能到终点就不加满，到不了加满)，如果前面
//有加油站价格比当前加油站价格低，就加油加到刚好到那个加油站就行，不能多加。
int main() {
    scanf("%d %d %d %d", &tank, &dis, &waste, &n);
    node start = {-1, -1};
    double cost = 0;
    int curdi = 0;
    for(int i = 0; i < n; ++i) {
        double p;
        int d;
        scanf("%lf %d", &p, &d);
        bool f = false;
        node tmp = {p, d};
        for(int i = 0; i < v.size(); ++i) {
            if(v[i].di == d) {
                if(v[i].price > p) {
                    v[i].price = p;
                    if(d == 0) {
                        start = tmp;
                    }
                }
                f = true;
                break;
            }
        }
        if(f) {
            continue;
        }
        if(d == 0) {
            start = tmp;
        }
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);
    // for(int i = 0; i < v.size(); ++i) {
    //     cout << v[i].di << ' ' << v[i].price << endl;
    // }
    if(start.di < 0) {
        cout << "The maximum travel distance = 0.00" << endl;
        exit(0);
    }
    // cout << tank*waste << endl;
    node curstation = start;
    double curtankdis = 0;
    bool ok = 0;
    while(1) {
        node nextStation = {-1, -1};
        double minprice = 100000;
        int flag = 0;
        for(int i = 0; i < v.size(); ++i) {
            if(v[i].di <= curdi + tank*waste && v[i].di > curdi) {
                // cout << v[i].price << ' ' << curstation.price << ' ' << minprice << endl;
                if(v[i].price < curstation.price) {
                    // cout << "1" << endl;
                    flag = 1;
                    nextStation = v[i];
                    break;
                } else if (v[i].price < minprice ) {
                    flag = 2;
                    // cout << "2" << endl;
                    minprice = v[i].price;
                    nextStation = v[i];
                }
                // getchar();
            }
        }
        if(!flag) {
            break;
        }
        if(flag == 2) {
            if(tank*waste + curdi < dis) {
                cost += curstation.price*(tank*waste - curtankdis);
                curtankdis = tank*waste;
            } else {
                // printf("%.2lf\n", cost);
                cost += curstation.price*(dis - curdi);
                // cout << curstation.price*(dis - curdi) << endl;
                // cout << curstation.price << ' ' << curstation.di << ' ' << curdi << ' ' << dis << endl;
                // // printf("%.2lf\n", cost);
                
                curdi = dis;
                curtankdis = 0;
                ok = 1;
                break;
            }
        } else {
            cost += curstation.price*(nextStation.di - curdi - curtankdis);
            curtankdis += nextStation.di - curdi - curtankdis;
        }
        curtankdis = curtankdis - (nextStation.di - curdi);
        // cout << flag << ' ' << curdi << ' ' << nextStation.di << ' ' << nextStation.price << ' ' << curtankdis << endl;
        // cout << cost << endl;
        // printf("%.2lf\n", cost/waste);
        curdi = nextStation.di;
        curstation = nextStation;
    }

    if(curdi + tank*waste < dis) {
        printf("The maximum travel distance = %.2lf", (double)(curdi + tank*waste));
    } else {
        // cout << curtankdis << ' ' << curdi << ' ' << ok << endl;
        if(!ok) {
            cost += curstation.price*(dis - curdi - curtankdis);
        }
        printf("%.2f\n", cost/waste);
    }
    
}