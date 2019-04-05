#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct node {
    int score;
    string name;
    string id;
} node;

vector <node> v;

int n, m;

int cmp1(node a, node b) {
    return a.id < b.id;
}

int cmp2(node a, node b) {
    if(a.name != b.name) {
        return a.name < b.name;
    } else {
        return a.id < b.id;
    }
    
}

int cmp3(node a, node b) {
    if(a.score != b.score) {
        return a.score < b.score;
    } else {
        return a.id < b.id;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        char buf1[16];
        char buf2[16];
        int sc;
        scanf("%s %s %d", buf1, buf2, &sc);
        string name = buf2;
        string id = buf1;
        node tmp = {sc, name, id};
        v.push_back(tmp);
    }

    switch (m)
    {
        case 1: {
            sort(v.begin(), v.end(), cmp1);
        } break;
        case 2: {
            sort(v.begin(), v.end(), cmp2);
        } break;
        case 3: {
            sort(v.begin(), v.end(), cmp3);
        } break;
    }
    vector <node> :: iterator it = v.begin();
    while(it != v.end()) {
        printf("%s %s %d\n", it->id.data(), it->name.data(), it->score);
        it++;
    }


}