#include <bits/stdc++.h>
using namespace std;

//�]���̵u���|�@�w�O�C����u�Q���L�⦸�A�ҥH�i�H���������ܼƫ᭼2�N�n�F�C
//���o�D�n�ƧǪ���]�O�]���n���r��ǳ̤p�A�ҥH�n�q0�}�l�A�����L�F�~�̤p���}�l���X
//�]�����X���@�ӾF�~��|�^��o���I�A�ҥH�٭n�A��X�@���o���I

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
