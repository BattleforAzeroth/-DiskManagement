#include "DiskManagement.h"
#include <algorithm>

bool comp(const request& a, const request& b){
    return a.num < b.num;
}

void DiskManagement::FCFS(){
    ans = requests;
}

void DiskManagement::SSTF(){
    ans.clear();
    int pos = now;
    vector<request>::iterator nearreq;
    int minpos;
    vector<request> copy(requests);
    while(!copy.empty()){
        nearreq = copy.begin();
        minpos = abs(copy.begin()->num - pos);
        for(auto it = copy.begin();it != copy.end();it++){  //找最近
            if (abs(it->num - pos) < minpos){
                minpos = abs(it->num - pos);
                nearreq = it;
            }
        }
        ans.push_back(*nearreq);    //选择最近请求
        pos = nearreq->num;         //更新当前位置
        copy.erase(nearreq);
    }
}

void DiskManagement::SCAN(){
    ans.clear();
    vector<request> r, l;
    for (auto it = requests.begin();it != requests.end();it++){     //对请求分类
        if (it->num > now) {
            r.push_back(*it);
        }
        else if (it->num < now){
            l.push_back(*it);
        }
        else ans.push_back(*it);
    }
    sort(r.begin(), r.end(), comp);
    sort(l.begin(), l.end(), comp);
    reverse(l.begin(), l.end());
    if (now_d){
        /*
        ans.insert(ans.end(), r.begin(), r.end());
        ans.insert(ans.end(), l.begin(), r.end());
        感觉代码没问题，但是会报错
        */
        for (auto it = r.begin();it != r.end();it++)
            ans.push_back(*it);
        for (auto it = l.begin();it != l.end();it++)
            ans.push_back(*it);
    }
    else {
        /*
        ans.insert(ans.end(), l.begin(), r.end());
        ans.insert(ans.end(), r.begin(), r.end());
        */
        for (auto it = l.begin();it != l.end();it++)
            ans.push_back(*it);
        for (auto it = r.begin();it != r.end();it++)
            ans.push_back(*it);
    }

}

float DiskManagement::avg(){
    int dis = 0;
    if (ans.empty()) return 0;
    int loc1 = now;
    int loc2;
    for (auto it = ans.begin();it != ans.end();it++){
        loc2 = loc1;
        loc1 = it->num;
        dis += abs(loc1 - loc2);
    }
    return float(dis) / float(ans.size());
}
