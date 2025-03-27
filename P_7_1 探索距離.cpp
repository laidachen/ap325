#include <bits/stdc++.h>
using namespace std;

//bfs�L����z�O�u�n������i-1�N���I�A����i�N�P���e�C�@�N���I���Q�o�{�L�F�A�ҥH�ڦb������i�N���I���ɭԡA�p�G�L���F�~�S���Q�o�{���ܡA�@�w�Oi+1�N���I
//�ҥHbfs�n����Ϧs�_�ӡA�����٭n���@�ӥi�H�M�w�n���X�I������(queue)�A�����٭n���@�Ӱ}�C�s��o���I���S���Q�o�{�A�٭n���@�Ӧs����I���Z��

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
