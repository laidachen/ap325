#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m,temp,p,s,t;
	cin>>n>>m;
	vector<int> weight(2*n,0);
	vector<int> out[2*n];
	vector<int> in[2*n];
	vector<int> command;
	for (int i=n; i<=2*n-1; i++) {
		cin>>weight[i];
	}
	for (int i=0; i<m; i++) {
		cin>>temp;
		command.push_back(temp);
	}
	for (int i=0; i<n-1; i++) {
		cin>>p>>s>>t;
		out[p].push_back(s);
		out[p].push_back(t);
		in[s].push_back(p);
		in[t].push_back(p);
	}

	//bfs
	return 0;
}
