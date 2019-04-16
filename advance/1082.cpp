#include <iostream>
#include <string>
#include <vector>
using namespace std;
const char buf[10][10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
vector <const char*> res;
bool output=false;
void printNum(int n, const char* last) {
    if(!n) {
        return ;
    }
    int thousand = n / 1000;
    int hundred = (n % 1000) / 100;
    int ten = (n % 100) / 10;
    int dig = n % 10;
    int flag = false;
    if(thousand) {
        res.push_back(buf[thousand]);
        res.push_back("Qian");
        output = true;
        flag = false;
    } else if(output){
        res.push_back(buf[0]);
        flag = true;
    }
    if(hundred) {
        res.push_back(buf[hundred]);
        res.push_back("Bai");
        output = true;
        flag = false;
    } else if(!flag && output && (ten != 0 || dig != 0)){
        res.push_back(buf[0]);
        flag = true;
    }
    if(ten) {
        res.push_back(buf[ten]);
        res.push_back("Shi");
        output = true;
    } else if(!flag && output && (dig != 0)){
        res.push_back(buf[0]);
        flag = true;
    }
    if(dig) {
        res.push_back(buf[dig]);
        output = true;
    }
    if(last)
        res.push_back(last);
}

int main() {
    
    string num;
    cin >> num;
    
    if(num[0] == '-') {
        // printf("Fu ");
        res.push_back("Fu");
        num.erase(0, 1);
    }
    int n = atoi(num.data());
    if(n == 0) {
        printf("%s\n", buf[0]);
        exit(0);
    }
    int hundredMillion = n / 100000000;
    int wan = (n % 100000000) / 10000;
    int other = (n % 10000);
    
    printNum(hundredMillion, "Yi");
    printNum(wan, "Wan");
    printNum(other, NULL);
    printf("%s", res[0]);
    for(int i = 1; i < res.size(); ++i) {
        printf(" %s", res[i]);
    }
    putchar('\n');
}