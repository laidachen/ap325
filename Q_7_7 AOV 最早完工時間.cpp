#include <bits/stdc++.h>
using namespace std;

//先找出topo順序還能算題目
//設needtime[n]完成n這工作加前面做過的最小時間，needtime[n]就是n的in neighbor所花時間的最大值加上自己，因為放在其他地方不會滿足先做a才能做n的順序
//在算的時候要計算一個最大值now，用來記錄目前時間的最大值，假如說超過這最大值就要更新，小於的話就代表工作能在這時間內完成
//之後還要存一個完成時間他選的工作，如果這裡每個工作往後延，完成時間就會變長，所以都是關鍵工作
//因為可能有很多個完成時間都一樣的情況，所以要存起來每個完成時間一樣他的關鍵工作，最後再用SET過濾掉就好了

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,g,e;
    int now = 0;
    int needtime[10001] = {0};
    int inde[10001] = {0};
    cin>>n>>m;
    vector<int> in[n+1];
    vector<int> out[n+1];
    vector<int> a[n+1];
    vector<int> topo;
    vector<int> time(n+1,0);
    vector<int> again;
    vector<int> againnow;
    set<int> s;
    queue<int> q;
    for (int i=1; i<=n; i++) {
        cin>>time[i];
    }
    for (int i=0; i<m; i++) {
        cin>>g>>e;
        out[g].push_back(e);
        in[e].push_back(g);
        inde[e]+=1;
    }
    for (int i=1; i<=n; i++) {
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
    for (int i=0; i<topo.size(); i++) {
        if (in[topo[i]].size()==0) {
            needtime[topo[i]] = time[topo[i]];
            if (needtime[now]<needtime[topo[i]]) {
                now = topo[i];
            }
            a[topo[i]].push_back(topo[i]);
        } else {
            int maxn = INT_MIN;
            int where = 0;
            for (int i2=0; i2<in[topo[i]].size(); i2++) {
                //也有可能一樣所以也要全部加進來
                if (needtime[in[topo[i]][i2]]==maxn) {
                    again.push_back(in[topo[i]][i2]);
                }
                if (needtime[in[topo[i]][i2]]>maxn) {
                    maxn = needtime[in[topo[i]][i2]];
                    where = in[topo[i]][i2];
                    again.clear();
                    again.push_back(where);
                }
            }
            needtime[topo[i]] = needtime[where]+time[topo[i]];
            for (int i2=0; i2<again.size(); i2++) {
                for (int i3=0; i3<a[again[i2]].size(); i3++) {
                    a[topo[i]].push_back(a[again[i2]][i3]);
                }
            }
            again.clear();
            a[topo[i]].push_back(topo[i]);
            if (needtime[topo[i]]==needtime[now]) {
                againnow.push_back(topo[i]);
            }
            if (needtime[topo[i]]>needtime[now]) {
                now = topo[i];
                againnow.clear();
                againnow.push_back(now);
            }
        }
    }
    cout<<needtime[now]<<endl;
    for (int i=0; i<againnow.size(); i++) {
        for (int i2=0; i2<a[againnow[i]].size(); i2++) {
            s.insert(a[againnow[i]][i2]);
        }
    }
    for (auto it=s.begin(); it!=s.end(); it++) {
        cout<<*it<<" ";
    }
    return 0;
}
