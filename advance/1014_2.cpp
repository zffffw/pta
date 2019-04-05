#include <iostream>
#include <queue>
using namespace std;

int result[1001]; //存放结果
int lastTime[1001]; //存放处理时间
queue <int> window[20]; //窗口队列

int windowNum, maxLine, customNum, quesNum;
int ok; //成功服务人数
int debug = false;
void predit() {
    int leaveCusNum = customNum;
    int curCustom = 0;
    for(int t = 0; t < 540; ++t) {
        if(debug) {
            cout << endl << "t" << t;
            cout << endl << "result:" ;
            for(int i = 0; i < customNum; ++i) {
                cout << result[i] << ' ';
            }
            cout << endl << "window:";
            for(int i = 0; i < windowNum; ++i) {
                if (window[i].size() > 0) {
                    cout << window[i].front() << ' ';
                } else {
                    cout << "**" << ' ';
                }
            }
            cout << endl << "curCustNum:" << curCustom << endl;; 
        }
        // getchar();
        for(int i = 0; i < windowNum; ++i) {
            for(int j = 0; j < window[i].size(); ++j) {
                if(result[window[i].front()] == t) {
                    window[i].pop();
                    ok += 1;
                    
                    if(!window[i].empty()) {
                        result[window[i].front()] = t + lastTime[window[i].front()]; //队列有人排队，进入服务
                    }
                }
            }
        }
        if(ok == customNum) {
            break;
        }

        int full = 0;
        while(!full && curCustom < customNum) {
            int mini = 0;
            full = 1;
            for(int i = 0; i < windowNum; ++i) {
                if(window[mini].size() > window[i].size()) {
                    mini = i;
                }
            }
            if(window[mini].size() < maxLine) {
                full = 0;
                
                if(window[mini].size() == 0) { //如果队列为空，则直接进入服务，计算出服务完成后的结果
                    result[curCustom] = t + lastTime[curCustom];             
                }
                window[mini].push(curCustom);
                curCustom += 1;
            }
        }
    }
}

void min2hourmin(int cut) {
    int cutnum = result[cut - 1];
    int hour = 8 + cutnum / 60;
    int min = cutnum % 60;
    if ( result[cut - 1] == 0 || result[cut - 1] > 599) {
        printf("Sorry\n");
    } else {
        if(hour / 10 == 0) {
            printf("0");
        }
        printf("%d:", hour);
        if(min / 10 == 0) {
            printf("0");
        }
        printf("%d\n", min);
    }
    
}

int main(int argc, char * argv[]) {
    debug = argc - 1;
    cin >> windowNum >> maxLine >> customNum >> quesNum;
    for(int i = 0; i < customNum; ++i) {
        cin >> lastTime[i];
    }
    predit();
    for(int i = 0; i < quesNum; ++i) {
        int tmp;
        cin >> tmp;
        min2hourmin(tmp);
    }
}
