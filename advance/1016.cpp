#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef struct timeElem {
    string start;
    string end;
    int cost;
} timeElem;

typedef struct TElem {
    string name;
    string time;
    string status;
} TElem;

typedef vector <TElem> TList;
TList L;

typedef struct timeList {
    vector <timeElem> t[12];
} timeList;

map <string, timeList> M;

int cost[24];

bool cmp(TElem a, TElem b) {
    if(a.name.compare(b.name.data()) < 0) {
        return true;
    } else if(a.name.compare(b.name.data()) == 0 && a.time.compare(b.time.data()) < 0) {
        return true;
    } else {
        return false;
    }
}

void calCost(string name, string start, string end) {
    int month_, day_, hour_, mini_;
    int _month, _day, _hour, _mini;
    int money;
    // day = static_cast<int> strtol(start.substr(3, 5).c_str,&end,16);
    cout << start << ' ' << end << ' ' << endl;
    sscanf(start.data(), "%d:%d:%d:%d",&_month, &_day, &_hour, &_mini);
    sscanf(end.data(), "%d:%d:%d:%d", &month_, &day_, &hour_, &mini_);
    int totalday = hour_ > _hour? day_ - _day: day_ - _day - 1;
    int totalhour = mini_ > _mini? hour_ - _hour: hour_ - _hour - 1;
    if (hour_ < _hour) {
        totalhour += 24;
    }
    int totalmin = mini_ > _mini? mini_ - _mini: mini_ + 60 - _mini;
    cout << totalday << ' ' << totalhour << ' ' << totalmin << endl;
    // cout << _month << ' ' << _day << ' ' << _hour << ' ' << _mini << ":" << month_ << ' ' << day_ << ' ' << hour_ << ' ' << mini_ << endl;
    if(totalday > 0) {
        int totalDayMoney = 0;
        for(int i = 0; i < 24; ++i) {
            totalDayMoney += cost[i]*60;
        }
        money += totalDayMoney*totalday;
    }
    if(totalhour > 1) {
        int beginHour = _hour + 1;
        int tmp = totalhour - 1;
        for(int i = 0; i < tmp; ++i) {
            money += cost[(i + beginHour) % 24]*60;
        }
    }
    if(totalmin > 0) {
        money += cost[hour_]*mini_ + cost[_hour]*(60 - _mini);
    }
    map <string, timeList> :: iterator it;
    timeElem ti;
    ti.cost = money;
    ti.start = start;
    ti.end = end;
    it = M.find(name);
    it->second.t[month_].push_back(ti);
}

void getRes() {
    string nowName = L[0].name;
    int i = 0;
    float totalCost = 0;
    string last = L[0].name;
    while(i < L.size() - 1) {
        string timeStart, timeEnd;
        if(last != L[i].name) {
            totalCost = 0;
        }
        // string name1, time1, status1, name2, time2, status2;
        if(L[i].name == L[i + 1].name) {
            if(L[i].status == "on-line" && L[i + 1].status == "off-line") {
                timeStart = L[i].time;
                timeEnd = L[i + 1].time;
                // cout << L[i].name << " ";
                calCost(L[i].name, timeStart, timeEnd);
                // cout << c << endl;
                i += 2;
                continue;
            }
        }
        ++i;
        last = L[i].name;
    }
}

int main() {
    for(int i = 0; i < 24; ++i) {
        cin >> cost[i];
    }
    int num;
    cin >> num;
    
    for(int i = 0; i < num; ++i) {
        TElem tmp;
        cin >> tmp.name >> tmp.time >> tmp.status;
        L.push_back(tmp);
    }
    sort(L.begin(), L.end(), cmp);
    int count = 0;
    map <string, timeList>::iterator it;
    for(int i = 0; i < num; ++i) {
        it = M.find(L[i].name);
        if(it == M.end()) {
            timeList tmp;
            // M.insert(make_pair(L[i].name, tmp));
            M.insert(make_pair(L[i].name, tmp));
        }
    }  
    for(int i = 0; i < num; ++i) {
        it = M.find(L[i].name);
        if(it != M.end()) {
            cout << it->first << endl;
        }
    }
    getRes();
}