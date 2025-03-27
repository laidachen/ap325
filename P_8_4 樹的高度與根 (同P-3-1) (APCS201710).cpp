#include <bits/stdc++.h>
using namespace std;

//這題設dp[i]為跟點i距離最長的子孫的距離，那他的遞迴式就是dp[i] = max(dp[k])+1，k是這個點的out neighbor就是他的孩子，然後還要加一，因為往上一步
//接下來要有一個往上走訪的順序，就類似topo順序的作法，把沒孩子的先近來，之後把他的parent的孩子數扣一，如果他孩子數等於0，就把他加進queue算
//就能bottom up上去了

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,temp;
    cin>>n;
    vector<int> in[n+1];
    vector<int> out[n+1];
    vector<int> child(n+1,0);
    queue<int> q;
    vector<int> topo;
    vector<int> dp(n+1,0);
    for (int i=1; i<=n; i++) {
        int k;
        cin>>k;
        child[i] = k;
        for (int i2=0; i2<k; i2++) {
            cin>>temp;
            in[temp].push_back(i);
            out[i].push_back(temp);
        }
    }
    for (int i=1; i<=n; i++) {
        if (child[i]==0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        for (int i=0; i<in[q.front()].size(); i++) {
            child[in[q.front()][i]]-=1;
            if (child[in[q.front()][i]]==0) {
                q.push(in[q.front()][i]);
            }
        }
        topo.push_back(q.front());
        q.pop();
    }
    cout<<topo[topo.size()-1]<<endl;
    int total = 0;
    for (int i=0; i<topo.size(); i++) {
        if (out[topo[i]].size()==0) {
            continue;
        }
        int maxn = 0;
        for (int i2=0; i2<out[topo[i]].size(); i2++) {
            maxn = max(maxn,dp[out[topo[i]][i2]]);
        }
        dp[topo[i]] = maxn+1;
        total+=maxn+1;
    }
    cout<<total;
    return 0;
}
