#include <iostream>
#include <stack>
using namespace std;
//线段树
typedef struct node {
    int right;
    int left;
    int weight;
    int addFlag;
} node;

class segTree {
    public:
        int Size;
        node* T;
        segTree(int size):Size(4*size + 10) {
            T = new node[Size];
        }
        ~segTree() {
            delete [] T;
        }
        void build(int l, int r, int k, int* arr) {
            // cout << l << ' ' << r << ' ' << k;
            // getchar();
            T[k].left = l;
            T[k].right = r;
            if(l == r) {
                T[k].weight = arr[l];
                return ;
            }
            int mid = (l + r) / 2;
            build(l, mid, 2*k, arr);
            build(mid + 1, r, 2*k + 1, arr);
            T[k].weight = T[2*k].weight + T[2*k + 1].weight;
        }
        void chgPoint(int k, int v, int index) {
            if(T[k].left == T[k].right) {
                T[k].weight += v;
                return ;
            }
            if(T[k].addFlag) down(k);
            int mid = (T[k].left + T[k].right) / 2;
            if(mid >= index) {
                chgPoint(k*2, v, index);
            } else {
                chgPoint(k*2 + 1, v, index);
            }
            T[k].weight = T[2*k].weight + T[2*k + 1].weight;
        }
        void down(int k) {
            T[2*k].addFlag += T[k].addFlag;
            T[2*k + 1].addFlag += T[2*k + 1].addFlag;
            T[2*k].weight += T[k].addFlag*(T[2*k].right - T[2*k].left + 1);
            T[2*k + 1].weight += T[k].addFlag*(T[2*k + 1].right - T[2*k + 1].left + 1);
            T[k].addFlag = 0;
        }
        int getPoint(int k, int index) {
            int res;
            if(T[k].left == T[k].right) {
                return T[k].weight;
            }
            if(T[k].addFlag) down(k);
            int mid = (T[k].left + T[k].right) / 2;
            if(mid >= index) {
                res = getPoint(2*k, index);
            } else {
                res = getPoint(2*k + 1, index);
            }
            return res;
        }
        void chgSeg(int l, int r, int k, int v) {
        
            if(T[k].right <= r && T[k].left >= l) {
                T[k].addFlag += v;
                T[k].weight += v*(T[k].right - T[k].left + 1);
                return ;
            }
            if(T[k].addFlag) down(k);
            int mid = (T[k].left + T[k].right) / 2;
            if(l <= mid) chgSeg(l, r, 2*k, v);
            if(r > mid) chgSeg(l, r, 2*k + 1, v);
            T[k].weight = T[2*k].weight + T[2*k + 1].weight;
        }
        int getSeg(int l, int r, int k) {
            
            if(T[k].right <= r && T[k].left >= l) {
                // cout << "(****" << T[k].weight << endl;
                return T[k].weight;
            }
            if(T[k].addFlag) down(k);
            int mid = (T[k].left + T[k].right) / 2;
            // cout << T[k].left << ' ' << mid << ' ' << T[k].right << ' ' << k << ' ';
            // getchar();
            int res = 0;
            if(l <= mid) res += getSeg(l, r, 2*k);
            if(r > mid) res += getSeg(l, r, 2*k + 1);
            // cout << res << endl;
            return res;
        }
};

stack <int> st;
segTree ST(100001);
int num[100010]={0};
int n;

int getMedium() {
    int k = st.size();
    k = k % 2 ? (k + 1)/2 : k/2 ;
    int begin = 1, end = 100000;
    while(begin <= end) {
        
        int mid = (begin + end) / 2;
        int tmp = ST.getSeg(1, mid, 1);
        // cout << begin << ' ' << end << ' ' << mid << endl;
        if( tmp < k) {
            begin = mid + 1;
        } else if(tmp >= k) {
            end = mid - 1;
        }
    }
    return begin;
}
int main() {
    scanf("%d", &n);
    ST.build(1, 100000, 1, num);
    
    for(int i = 0; i < n; ++i) {
        char buf[128];
        scanf("%s", buf);
        switch (buf[1])
        {
            case 'o': {
                if(!st.size()) {
                    printf("Invalid\n");
                } else {
                    printf("%d\n", st.top());
                    ST.chgPoint(1, -1, st.top());
                    st.pop();
                }
            }break;
            case 'e': {
                if(!st.size()) {
                    printf("Invalid\n");
                } else {
                    printf("%d\n", getMedium());
                }
            } break;
            case 'u': {
                int tmp;
                scanf("%d", &tmp);
                st.push(tmp);
                ST.chgPoint(1, 1, tmp);
                // cout << ST.T[2].weight << endl;
            } break;
        }
    }
}