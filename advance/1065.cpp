#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

string sa, sb, sc;
int T;


//t1 > t2?
bool cmp(string t1, string t2) {
    if(t1[0] != '-' && t2[0] == '-') {
        return true;
    } else if(t1[0] == '-' && t2[0] != '-') {
        return false;
    } else if(t1[0] == '-' && t2[0] == '-') {
        t1 = t1.substr(1);
        t2 = t2.substr(1);
        if(t1.size() > t2.size()) {
            return false;
        } else if (t1.size() < t2.size()) {
            return true;
        } else {
            return t1 < t2;
        }
    } else {
        if(t1.size() < t2.size()) {
            return false;
        } else if (t1.size() > t2.size()) {
            return true;
        } else {
            return t1 > t2;
        }
    }
}


// a + (-b)
string minus_(string a, string b) {
    string res;
    string tmin, tmax;
    int minusflag = 0;
    if(cmp(a, b.substr(1)) || a == b) {
        tmax = a;
        tmin = b.substr(1);
    } else {
        minusflag = 1;
        tmax = b.substr(1);
        tmin = a;
    }
    int div = tmax.size() - tmin.size();
    // cout << tmax << ' ' << tmin << endl;
    int msize = tmin.size();
    int last = 0;
    for(int i = msize - 1; i >= 0; --i) {
        char nn;
        // printf("%d %d\n", tmax[i + div], tmin[i]);
        int tmp = tmax[i + div] - tmin[i] - last;
        if( tmp < 0) {
            last = 1;
            nn = tmp + 10 + '0';
        } else {
            last = 0;
            nn = tmp + '0';
        }
        // printf("%d\n", nn);
        // cout << tmp << endl;
        res.insert(0, 1, nn);
    }
    // cout << res << endl;
    for(int i = div - 1; i >= 0; --i) {
        char nn;
        int tmp = tmax[i] - last - '0';
        if( tmp < 0) {
            last = 1;
            nn = tmp + 10 + '0';
        } else {
            last = 0;
            nn = tmp + '0';
        }
        
        res.insert(0, 1, nn);
    }
    while(res[0] == '0' && res.size() > 1) {
        res.erase(0, 1);
    }
    if(minusflag && res[0] != '0') {
        res.insert(0, 1, '-');
    }
    return res;
}


// a + b || (-a) + (-b)
string add_ (string a, string b) {
    int minusflag = 0;
    if(a[0] == '-' && b[0] == '-') {
        minusflag = 1;
        a = a.substr(1);
        b = b.substr(1);
    }
    string res;
    string tmin, tmax;
    if (a.size() > b.size()) {
        tmin = b;
        tmax = a;
    } else {
        tmin = a;
        tmax = b;
    }

    int msize = min(tmin.size(), tmax.size());
    int div = tmax.size() - tmin.size();
    // cout << "div:" << div << endl;
    int last = 0;
    for(int i = msize - 1; i >= 0; --i) {
        char nn = (tmax[i + div] + tmin[i] + last - 2*'0') % 10 + '0';
        last = (tmax[i + div] + tmin[i] + last - 2*'0') / 10;
        res.insert(0, 1, nn);
    }
    for(int i = div - 1; i >= 0; --i) {
        char nn = (tmax[i] + last - '0') % 10 + '0';
        last = (tmax[i] + last - '0') / 10;
        res.insert(0, 1, nn);
    }
    if(last) {
        res.insert(0, 1, (char)(last + '0'));
    }
    if(minusflag) {
        res.insert(0, 1, '-');
    }
    return res;
}

int main() {
    scanf("%d", &T);
    for(int i = 0; i < T; ++i) {
        cin >> sa >> sb >> sc;
        printf("Case #%d: ", i + 1);
        int flag = 0;
        if((sa[0] == '-' && sb[0] == '-') || (sa[0] != '-' && sb[0] != '-')) {
            // cout << add_(sa, sb) << endl;
            if(cmp(add_(sa, sb), sc)) {
                flag = 1;
            }
        } else if(sa[0] == '-' && sb[0] != '-'){
            // cout << cmp(sa, sb) << endl;
            // cout << minus_(sb, sa) << endl;
            if(cmp(minus_(sb, sa), sc)) {
                flag = 1;
            }
        } else {
            // cout << "111111" << endl;
            // cout << minus_(sa, sb) << endl;
            if(cmp(minus_(sa, sb), sc)) {
                flag = 1;
            }
        }
        if(flag) {
            printf("true\n");
        } else {
            printf("false\n");
        }
    }
}