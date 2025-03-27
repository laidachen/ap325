#include <bits/stdc++.h>
using namespace std;

//dfs���g�k�O�λ��j�Ӽg�A�D�n���g�k�N�O���P�_�o�I���F�~���S���Q���X�L�A�p�G�S�����ܴN�q�䤤�@�ӾF�~�}�l�~�򩹸̭������A����Y��^�Ǧ^�ӡA�M��A���t�@�ӾF�~
//�]����@���I��dfs����A���Q�X�ݨ쪺�|�Φ��@�����A���A��䤤���X�L���I��dfs�٬O�u�|�Φ��o�����A�ҥH�i�H������S���X�L���I��dfs�N�n�F

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
