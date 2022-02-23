#include <iostream>
#include <vector>
using namespace std;


struct request {
    int num;    //磁道号
    string name;
};

class DiskManagement {
    int now;        //当前磁头所在磁道
    bool now_d;     //当前磁头移动方向;1:增大方向;0:减小方向
    vector<request> requests;
    vector<request> ans;
public:
    void FCFS();    //先来先服务
    void SSTF();    //最短寻道优先
    void SCAN();    //扫描算法（电梯算法）
    void set_d(bool d) { now_d = d; }
    void setNow(int n) { now = n; }
    void addreq(string req_name, int req_num){
        request p;
        p.name = req_name;
        p.num = req_num;
        requests.push_back(p);
    }
    vector<request> getAns() { return ans; }
    int getNow() { return now; }
    void reread() { requests.clear(); }
    void clear() { ans.clear(); }
    float avg();
};
