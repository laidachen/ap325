#include <bits/stdc++.h>
using namespace std;

//��bfs�A�C�������I�����X���줣�ਫ����A�M���L�[��queue�̭��A����Ū�����|��V���I��A�}�lŪ�̭����I�A�p�G�S�Q���X��B�i�H���o�A�̤p���s���ƴN�O�����I�����s���ƥ[�@


int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int m,n;
    int x =0;
    int y =0;
    int x2 = 0;
    int y2 = 0;
    string temp;
    cin>>m>>n;
    vector<vector<int>> map(m,vector<int> (n,0));
    vector<vector<int>> dis(m,vector<int> (n,-1));
    vector<vector<int>> visit(m,vector<int> (n,0));
    for (int i=0; i<m; i++) {
        cin>>temp;
        for (int i2=0; i2<n; i2++) {
            map[i][i2] = int(temp[i2])-48;
        }
    }
    queue<pair<int,int>> q;
    visit[0][0] = 1;
    q.push({0,0});
    dis[0][0] = 0;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        x2 = q.front().first;
        y2 = q.front().second;
        while (x2-1>=0) {
            if (map[y2][x2-1]==1||visit[y2][x2-1]==1) {
                break;
            }
            x2-=1;
            dis[y2][x2] = dis[y][x]+1;
            visit[y2][x2] = 1;
            q.push({x2,y2});

        }
        x2 = q.front().first;
        y2 = q.front().second;
        while (x2+1<n) {
            if (map[y2][x2+1]==1||visit[y2][x2+1]==1) {
                break;
            }
            x2+=1;
            dis[y2][x2] = dis[y][x]+1;
            visit[y2][x2] = 1;
            q.push({x2,y2});

        }
        x2 = q.front().first;
        y2 = q.front().second;
        while (y2-1>=0) {
            if (map[y2-1][x2]==1||visit[y2-1][x2]==1) {
                break;
            }
            y2-=1;
            dis[y2][x2] = dis[y][x]+1;
            visit[y2][x2] = 1;
            q.push({x2,y2});

        }
        x2 = q.front().first;
        y2 = q.front().second;
        while (y2+1<m) {
            if (map[y2+1][x2]==1||visit[y2+1][x2]==1) {
                break;
            }
            y2+=1;
            dis[y2][x2] = dis[y][x]+1;
            visit[y2][x2] = 1;
            q.push({x2,y2});

        }
        q.pop();
    }
    if (dis[m-1][n-1]!=-1) {
        dis[m-1][n-1]-=1;
    }
    cout<<dis[m-1][n-1];
    return 0;
}
