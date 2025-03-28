#include <bits/stdc++.h>
#define N 100001
using namespace std;
//設dp[i]為i這節點底下全部的重量，一開始只要先top down把全部節點都算過一遍，之後每次新增物品用dfs探索，然後每經過一個節點都把它加上這物品的重量就好了
vector<int> dp(2*N,-1);
vector<int> out[2*N];
vector<int> in[2*N];

int dpp(int n) {
	if (dp[n]!=-1) {
		return dp[n];
	} else {
		dp[n] = dpp(out[n][0])+dpp(out[n][1]);
		return dp[n];
	}
}

void dfs(int &n,int dot,int i) {
	if (dot>=n) {//走到底了
		dp[dot]+=i;
		cout<<dot;
	} else {
		int l = dp[out[dot][0]];
		int r = dp[out[dot][1]];
		if (l<=r) {
			dp[dot]+=i;
			dfs(n,out[dot][0],i);
		} else {
			dp[dot]+=i;
			dfs(n,out[dot][1],i);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m,temp,p,s,t;
	cin>>n>>m;
	vector<int> command;
	for (int i=n; i<=2*n-1; i++) {
		cin>>dp[i];
	}
	for (int i=0; i<m; i++) {
		cin>>temp;
		command.push_back(temp);
	}
	for (int i=0; i<n-1; i++) {
		cin>>p>>s>>t;
		out[p].push_back(s);
		out[p].push_back(t);
	}
	for (int i=0; i<command.size(); i++) {
		dpp(1);
		dfs(n,1,command[i]);
		if (i!=command.size()-1) {
			cout<<" ";
		}
	}
	return 0;
}
