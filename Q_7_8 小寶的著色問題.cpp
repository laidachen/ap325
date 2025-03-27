#include <bits/stdc++.h>
using namespace std;

//用bfs來探索，假如說這點的鄰居沒被拜訪過，就是下一代的點，設定為另一個顏色，如果拜訪過(可能同一代或是上一代)就看顏色有沒有相同，相同就代表矛盾了，要輸出no

int main(void) {
	ios::sync_with_stdio(0),cin.tie(0);
	int t,n,m,temp;
	cin>>t;
	for (int i=0; i<t; i++) {
		cin>>n>>m;
		vector<int> adj[n];
		vector<int> a;
		vector<int> visit(n,0);
		vector<int> color(n,0);
		int ok = 1;
		for (int i2=0; i2<m*2; i2++) {
			cin>>temp;
			a.push_back(temp);
		}
		for (int i2=0; i2<m*2; i2=i2+2) {
			if (a[i2]!=a[i2+1]) {
				adj[a[i2]].push_back(a[i2+1]);
				adj[a[i2+1]].push_back(a[i2]);
			}
		}
		for (int i2=0; i2<n; i2++) {
			if (visit[i2]==0) {
				queue<int> q;
				visit[i2] = 1;
				q.push(i2);
				//BFS
				while(!q.empty()) {
					for (int i3=0; i3<adj[q.front()].size(); i3++) {
						if (visit[adj[q.front()][i3]]==0) {
							if (color[q.front()]==0) {
								color[adj[q.front()][i3]] = 1;
							} else {
								color[adj[q.front()][i3]] = 0;
							}
							visit[adj[q.front()][i3]] = 1;
							q.push(adj[q.front()][i3]);
						} else {
							if (color[adj[q.front()][i3]]==color[q.front()]) {
								ok = 0;
								break;
							}
						}
					}
					q.pop();
				}
			}
            if (ok==0) {
                break;
            }
		}
        if (ok) {
            cout<<"yes"<<endl;
        } else {
            cout<<"no"<<endl;
        }
	}

	return 0;
}
