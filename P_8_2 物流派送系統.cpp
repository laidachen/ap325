#include <bits/stdc++.h>
using namespace std;

//這題要求一個點往上所花最大時間就是，dp[v] = dp[k]+w(v,k) ，k是v的in neighbor
//最長距離是dp[v] = dp[k]+1
//樹每個點的鄰居只有兩個，所以可以一直往上找

int main(void) {
	ios::sync_with_stdio(0),cin.tie(0);
	int n,a,w;
	int maxn = 0;
	int dism = 0;
	cin>>n;
	vector<pair<int,int>> in[n];//用pair存點跟權重
	vector<int> maxna(n,0);//這點往上的最大時間
	vector<int> disma(n,0);//這點往上的最大距離
	for (int i=1; i<=n-1; i++) {
		cin>>a>>w;
		in[i].push_back({a,w});
	}
	for (int i=1; i<=n-1; i++) {
		int total = 0;
		int dis = 0;
		queue<int> q;
		q.push(i);
		//bfs往上找
		while(!q.empty()&&q.front()!=0) {
            if (maxna[in[q.front()][0].first]!=0) {
                total+=maxna[in[q.front()][0].first]+in[q.front()][0].second;
                dis+=disma[in[q.front()][0].first]+1;
                break;
            }
			total+=in[q.front()][0].second;
			dis+=1;
			q.push(in[q.front()][0].first);
			q.pop();
		}
		maxn = max(maxn,total);
		dism = max(dism,dis);
		maxna[i] = total;
		disma[i] = dis;
	}
	cout<<maxn<<endl;
	cout<<dism<<endl;
	return 0;
}
