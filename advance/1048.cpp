#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> coins;
int n;
int m;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n ;++i) {
        int tmp;
        scanf("%d", &tmp);
        coins.push_back(tmp);
    }
    sort(coins.begin(), coins.end());
    int i = 0, j = n - 1;
    while(coins[j] > m) {
        j--;
    }
    int turn = 1;
    while(i < j) {
        if(coins[j] + coins[i] == m) {
            break;
        } 
        if (coins[j] + coins[i] > m) {
            turn = 1;
        } else if (coins[j] + coins[i] < m) {
            turn = 0;
        }
        if(turn) {
            j--;
        }else {
            i++;
        }
    }
    if(i == j) {
        printf("No Solution\n");
    } else {
        printf("%d %d\n", coins[i], coins[j]);
    }
}