#include <bits/stdc++.h>
using namespace std;

//dfs的寫法是用遞迴來寫，主要的寫法就是先判斷這點的鄰居有沒有被拜訪過，如果沒有的話就從其中一個鄰居開始繼續往裡面探索，到盡頭後回傳回來，然後再換另一個鄰居
//因為對一個點做dfs之後，有被訪問到的會形成一條路，那再對其中拜訪過的點做dfs還是只會形成這條路，所以可以直接對沒拜訪過的點做dfs就好了

vector<int> visit(50000,0);
vector<int> adj[50000];
vector<int> price(50000,0);

int dfs(int s) {
    visit[s] = 1;
    int money = price[s];
    for (int i=0; i<adj[s].size(); i++) {
        if (visit[adj[s][i]]==0) {
            money+=dfs(adj[s][i]);
        }
    }
    return money;
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        cin>>price[i];
    }
    for (int i=0; i<m; i++) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int mtotal = 0;
    for (int i=0; i<n; i++) {
        if (visit[i]==0) {
            mtotal = max(mtotal,dfs(i));
        }
    }
    cout<<mtotal;
    return 0;
}
