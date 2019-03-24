#include <iostream>
#define maxWeight 1000000
using namespace std;

int map[500][500];
int citiesSaveTeams[500];
int cityNums, roadNums, startp, endp;
// DJ[i][0] 距离， [2]标志是否访问过， [3] 救援队数
int DJ[500][4];
void init() {
    for(int i = 0; i < 500; ++i) {
        citiesSaveTeams[i] = 0;
        DJ[i][0] = maxWeight;
        DJ[i][1] = 1;
        DJ[i][2] = 0;
        DJ[i][3] = 0;
        for(int j = 0; j < 500; ++j) {
            if(i == j) {
                map[i][j] = 0;
            } else {
                map[i][j] = maxWeight;
            }
        }
    }
}

void showMap() {
    for(int i = 0; i < cityNums; ++i) {
        for(int j = 0; j < cityNums; ++j) {
            
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
}

void dijkstra() {
    int nowp = startp;
    DJ[startp][0] = 0;
    DJ[startp][1] = 1;
    DJ[startp][2] = 0;
    DJ[startp][3] = citiesSaveTeams[startp];
    for(int i = 0; i < cityNums; ++i) {
        DJ[i][3] = citiesSaveTeams[i];
    }
    for(int i = 0; i < cityNums; i++)
    {
        int minl = maxWeight;
        
        //下面这个for循环的功能类似冒泡排序，目的是找到未访问节点中d[j]值最小的那个节点，
        //作为下一个访问节点，用k标记
        for(int j = 0; j < cityNums; j++)
            if(!DJ[j][2] && DJ[j][0] < minl)
            {
                minl = DJ[j][0];
                nowp = j;
            }
        // cout << nowp << endl;
        //p[k]=d[k]; // 这是原来的代码，用下一 条代码替代。初始时，执行到这里k=1，而d[1]=0
       //从而p[1]等于0，这样的话，上面的循环在之后的每次执行之后，k还是等于1。
        DJ[nowp][2] = 1; //置1表示第k个节点已经访问过了
        // cout << "fdaf " << DJ[endp][1] << endl;
        for(int j = 0; j < cityNums; j++)
            if(map[nowp][j] != maxWeight && !DJ[j][2] && DJ[j][0] > DJ[nowp][0] + map[nowp][j]) {
                DJ[j][0] = DJ[nowp][0] + map[nowp][j];
                DJ[j][3] = DJ[nowp][3] + citiesSaveTeams[j];
                DJ[j][1] = DJ[nowp][1];
            } else if(map[nowp][j] != maxWeight && !DJ[j][2] && DJ[j][0] == DJ[nowp][0] + map[nowp][j]) {
                if (DJ[j][3] < DJ[nowp][3] + citiesSaveTeams[j]) {
                    DJ[j][3] = DJ[nowp][3] + citiesSaveTeams[j];
                }
                DJ[j][1] = DJ[j][1] + DJ[nowp][1];
            }
    }
    // for(int i = 0; i < cityNums; ++i) {
    //     cout << DJ[i][0] << ' ' << DJ[i][1] << ' ' << DJ[i][3] << endl;;
    // }
    // cout << endl;
    cout << DJ[endp][1] << ' ' << DJ[endp][3] << endl;
}


int main() {
    init();
    cin >> cityNums >> roadNums >> startp >> endp;
    DJ[startp][0] = 0;
    for(int i = 0; i < cityNums; ++i) {
        cin >> citiesSaveTeams[i];
    }
    int tempa, tempb, tempweight;
    for(int i = 0; i < roadNums; ++i) {
        cin >> tempa >> tempb >> tempweight;
        map[tempa][tempb] = tempweight;
        map[tempb][tempa] = tempweight;
    }
    // showMap();
    dijkstra();
}
