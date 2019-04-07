#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int poke[55];
int n;
int order[55];
void printcard(int i) {
    if(i >= 1 && i <= 13) {
        putchar('S');
    } else if (i >= 14 && i <= 26) {
        putchar('H');
    } else if (i >= 27 && i <= 39) {
        putchar('C');
    } else if (i >= 40 && i <= 52) {
        putchar('D');
    } else {
        putchar('J');
    }
    printf("%d", i % 13 == 0? 13 : i % 13);
}

void printP() {
    for(int i = 0; i < 54; ++i) {
        cout << poke[i] << ' ';
    }
    cout << endl;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= 54; ++i) {
        scanf("%d", &order[i]);
        poke[i] = i;
    }
    for(int i = 0; i < n; ++i) {
        int newPoke[55] = {0};
        for(int j = 1; j <= 54; ++j) {
            newPoke[order[j]] = poke[j];
        }
        for(int j = 1; j <= 54; ++j) {
            poke[j] = newPoke[j];
        }
        
    }
    printcard(poke[1]);
    for(int i = 2; i <= 54; ++i) {
        putchar(' ');
        printcard(poke[i]);
    }
    putchar('\n');
    
}