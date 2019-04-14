#include <iostream>
#include <stack>
using namespace std;

//树状数组 
typedef int* T;
class BIT {
    private:
        T Elem;
        int Size;
        int lowbit(int n) {
            return n & (-n);
        }
    public:
        BIT(int size):Size(size + 1) {
            Elem = new int[Size];
            for(int i = 0 ; i < Size ; ++i) {
                Elem[i] = 0;
            }
        }
        void Add(int x, int index) {
            while(index < Size) {
                Elem[index] += x;
                index += lowbit(index);
            }
        }
        int getSum(int right) {
            int res = 0;
            while(right > 0) {
                res += Elem[right];
                right -= lowbit(right);
            }
            return res;
        }
        int getSum(int left, int right) {
            return getSum(right) - getSum(left - 1);
        }
        ~BIT() {
            delete [] Elem;
        }
};


BIT bitarray(100001);
stack <int> st;
int n;

int getMedium() {
    int k = st.size();
    k = k % 2 ? (k + 1)/2 : k/2 ;
    int begin = 1, end = 100000;
    while(begin < end) {
        int mid = (begin + end) / 2;
        int tmp = bitarray.getSum(mid);
        if( tmp < k) {
            begin = mid + 1;
        } else if(tmp >= k) {
            end = mid;
        }
    }
    return begin;
}

int main() {
    scanf("%d", &n);
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
                    bitarray.Add(-1, st.top());
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
                bitarray.Add(1, tmp);
            } break;
        }
    }
}