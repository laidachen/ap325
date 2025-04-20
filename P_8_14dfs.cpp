#include <bits/stdc++.h>
#define N 100000
using namespace std;

vector<int> out[N];
vector<int> in[N];
int nowmax = 0;
int dfs(int n) {
    if (out[n].size()==0) {
        return 0;
    }
    vector<int> temp;
    for (int i=0; i<out[n].size(); i++) {
        temp.push_back(dfs(out[n][i])+1);
    }
    sort(temp.begin(),temp.end());
    if (temp.size()>=2) {
        nowmax = max(nowmax,temp[temp.size()-1]+temp[temp.size()-2]);
    } else {
        nowmax = max(nowmax,temp[temp.size()-1]);
    }
    return temp[temp.size()-1];
}


int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,a,b,where;
    cin>>n;
    for (int i=0; i<n-1; i++) {
        cin>>a>>b;
        out[a].push_back(b);
        in[b].push_back(a);
    }
    for (int i=0; i<n; i++) {
        if (in[i].size()==0) {
            where = i;
        }
    }
    dfs(where);
    cout<<nowmax;
    return 0;
}