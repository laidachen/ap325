#include <bits/stdc++.h>
using namespace std;

//因為最短路徑一定是每個邊只被走過兩次，所以可以直接紀錄變數後乘2就好了。
//那這題要排序的原因是因為要找到字典序最小，所以要從0開始，之後找他鄰居最小的開始探訪
//因為探訪完一個鄰居後會回到這個點，所以還要再輸出一次這個點

vector<int> adj[50000];
vector<int> road;
vector<int> visit(50000,0);

void dfs(int n) {
    road.push_back(n);
    for (int i=0; i<adj[n].size(); i++) {
        if (visit[adj[n][i]]!=1) {
            visit[adj[n][i]] = 1;
            dfs(adj[n][i]);
            road.push_back(n);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,a,b,w;
    int total = 0;
    cin>>n;
    for (int i=0; i<(n-1); i++) {
        cin>>a>>b>>w;
        total+=w;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=0; i<n; i++) {
        sort(adj[i].begin(),adj[i].end());
    }
    visit[0] = 1;
    dfs(0);
    cout<<total*2<<endl;
    for (int i=0; i<road.size(); i++) {
        cout<<road[i]<<" ";
    }
    return 0;
}
