#include <bits/stdc++.h>
using namespace std;

int dpmin[10000] = {0};
int dpmax[10000] = {0};

//設dpmin[i]為i點到s點的最短距離，他的轉移式是就是dpmin[i] = min(dpmin[k]+w(k,i)) for 點i的每個外鄰居(in-neighbor)，dp[s] = 0;
//dpmax[i]也是用同樣的概念
//運算的順序就是找出這張圖的topo順序

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,s,t,g,e,w;
    int inde[10000] = {0};//每個點的in-degree數
    int where = 0;
    cin>>n>>m;
    cin>>s>>t;
    vector<pair<int,int>> in[n];//每個點的in neighbor，順便用pair保存權重，方便後面可以直接加
    vector<int> out[n];//每個點的out neighbor
    vector<int> topo;
    queue<int> q;
    for (int i=0; i<m; i++) {
        cin>>g>>e>>w;
        in[e].push_back({g,w});
        out[g].push_back(e);
        inde[e]+=1;
    }
    //找出topo順序
    for (int i=0; i<n; i++) {
        if (inde[i]==0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        for (int i=0; i<out[q.front()].size(); i++) {
            inde[out[q.front()][i]]-=1;
            if (inde[out[q.front()][i]]==0) {
                q.push(out[q.front()][i]);
            }
        }
        topo.push_back(q.front());
        q.pop();
    }
    //找出s在topo順序裡面的哪裡，因為在他之後才有路可以走
    for (int i=0; i<n; i++) {
        if (topo[i]==s) {
            where = i;
            break;
        }
        dpmin[topo[i]] = INT_MAX;//表示不可能到達
        dpmax[topo[i]] = INT_MIN;
    }
    //開始dp
    for (int i=where+1; i<topo.size(); i++) {
        int totalmin = INT_MAX;
        int totalmax = INT_MIN;
        for (int i2=0; i2<in[topo[i]].size(); i2++) {
            //如果不是不可能才更新，不然會出錯很玄
            if (dpmin[in[topo[i]][i2].first]<INT_MAX) {
                totalmin = min(totalmin,dpmin[in[topo[i]][i2].first]+in[topo[i]][i2].second);
            }
            if (totalmax,dpmax[in[topo[i]][i2].first]>INT_MIN) {
                totalmax = max(totalmax,dpmax[in[topo[i]][i2].first]+in[topo[i]][i2].second);
            }
        }
        dpmin[topo[i]] = totalmin;
        dpmax[topo[i]] = totalmax;
    }
    if (dpmin[t]==INT_MAX) {
        cout<<"No path"<<endl;
    } else {
        cout<<dpmin[t]<<endl;
    }
    if (dpmax[t]==INT_MIN) {
        cout<<"No path"<<endl;
    } else {
        cout<<dpmax[t]<<endl;
    }
    return 0;
}
