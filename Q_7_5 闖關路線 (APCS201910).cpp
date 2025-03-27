#include <bits/stdc++.h>
using namespace std;


//如果用走到這要i步的點往左往右走，且之後傳送過後那個點沒被訪問過，就是i+1步的點，就類似bfs i-1代都訪問完了，然後在訪問i代時他的鄰居沒被訪問過，就是i+1代的
//所以用bfs找移動一次會到的點，之後加入清單，繼續找移動兩次會到的點，以此類推直到清單裡是空的
//然後還要計移動到這個點是不是第一次遇到，不是的話就代表前面有更好的解
//還要檢查左右移動會不會越界，不會越界也要找他傳送點會不會越界

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,p,l,r;
    cin>>n>>p>>l>>r;
    vector<int> map(n,0);
    vector<int> dis(n,-1);
    vector<int> visit(n,0);
    for (int i=0; i<n; i++) {
        cin>>map[i];
    }
    queue<int> q;
    visit[0] = 1;
    dis[0] = 0;
    q.push(0);
    while(!q.empty()) {
        if (q.front()-l>=0) {
            if (map[q.front()-l]<n&&map[q.front()-l]>=0) {
                if (visit[map[q.front()-l]]==0) {
                    visit[map[q.front()-l]] = 1;
                    dis[map[q.front()-l]] = dis[q.front()]+1;
                    q.push(map[q.front()-l]);
                    if (map[q.front()-l]==p) {
                        break;
                    }
                }
            }
        }
        if (q.front()+r<n) {
            if (map[q.front()+r]<n&&map[q.front()+r]>=0) {
                if (visit[map[q.front()+r]]==0) {
                    visit[map[q.front()+r]] = 1;
                    dis[map[q.front()+r]] = dis[q.front()]+1;
                    q.push(map[q.front()+r]);
                    if (map[q.front()+r]==p) {
                        break;
                    }
                }
            }
        }
        q.pop();
    }
    if (p<n&&p>=0) {
        cout<<dis[p];
    } else {
        cout<<-1;
    }
    return 0;
}
