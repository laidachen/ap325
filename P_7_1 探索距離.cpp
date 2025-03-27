#include <bits/stdc++.h>
using namespace std;

//bfs他的原理是只要探索完i-1代的點，那第i代與往前每一代的點都被發現過了，所以我在探索第i代的點的時候，如果他的鄰居沒有被發現的話，一定是i+1代的點
//所以bfs要先把圖存起來，之後還要有一個可以決定要拜訪點的順序(queue)，之後還要有一個陣列存放這個點有沒有被發現，還要有一個存跟原點的距離

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,s,g,e;
    int total = 0;
    int distotal = 0;
    cin>>n>>m;
    cin>>s;
    vector<int> adj[n];
    for (int i=0; i<m; i++) {
        cin>>g>>e;
        adj[g].push_back(e);
    }
    //bfs
    queue<int> d;
    vector<int> visit(n,0);
    vector<int> dis(n,0);
    d.push(s);
    visit[s] = 1;
    while (!d.empty()) {
        for (int i=0; i<adj[d.front()].size(); i++) {
            if (visit[adj[d.front()][i]]==0) {
                dis[adj[d.front()][i]] = dis[d.front()]+1;
                visit[adj[d.front()][i]] = 1;
                d.push(adj[d.front()][i]);
                total+=1;
                distotal+= dis[adj[d.front()][i]];
            }
        }
        d.pop();
    }
    cout<<total<<endl;
    cout<<distotal<<endl;
    return 0;
}
