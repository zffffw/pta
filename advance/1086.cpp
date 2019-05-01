#include <iostream>
#include <stack>
using namespace std;
typedef struct node {
    int idx;
    int times;
} node;

int main() {
    stack <node> s;
    int n;
    scanf("%d", &n);
    bool output = false;
    for(int i = 1; i <= 2*n; ++i) {
        char buf[128];
        scanf("%s", buf);
        switch (buf[1])
        {
            case 'u': {
                int tmp;
                scanf("%d", &tmp);
                node t = {tmp, 0};
                s.push(t);
            } break;
            case 'o': {
                s.top().times ++;
                while(s.top().times == 2) {
                    if(output)
                        putchar(' ');
                    printf("%d", s.top().idx);
                    s.pop();
                    s.top().times ++;
                    output = true;
                }
            } break;
        }
    }
    while(!s.empty()) {
        if(output)
            putchar(' ');
        printf("%d", s.top().idx);
        s.pop();
    }
}