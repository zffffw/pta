#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;
stack <int> st;
map <int, int> mt;

int n;
int num[100001];
int numsum[100001];
bool change;

int getMedium() {
    int k = st.size();
    k = k % 2? (k + 1)/2 : k/2;
    int cnt = 0;
    int res = 0;
    if(!change) {
        int begin = 1, end = 100000;
        while(begin < end) {
            int mid = (begin + end) / 2;
            if(numsum[mid] < k) {
                begin = mid + 1;
            } else if(numsum[mid] > k) {
                if(numsum[mid] - num[mid] < k) {
                    return mid;
                } else {
                    end = mid - 1;
                }
            } else if(numsum[mid] == k) {
                return mid;
            }
        }
    } else {
        change = false;
        for(int i = 1; i <= 100000; ++i) {
            cnt += num[i];
            numsum[i] = cnt;
            if(cnt >= k && !res) {
                res = i;
            }
        }
    }
    return res;
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
                    num[st.top()] --;
                    st.pop();
                    change = true;
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
                num[tmp] ++;
                change = true;
            } break;
        }
    }
}