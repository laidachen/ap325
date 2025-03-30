#include <bits/stdc++.h>
#define N 200000
using namespace std;
int maxn = 0;
vector<int> out[N];
vector<int> dotc(N,0);
//這題用dfs探索每一條路，之後要紀錄最大值，只要設一個變數，之後看這個點的計數器加上他有沒有大於這變數，有的話就更新
//然後探索完這個節點全部路徑後，自己要回推到上一個節點，才能給上一個節點探索他下一個節點

void dfs(int n,vector<int> &count) {
    count[dotc[n]]+=1;//一開始先加自己進去
    maxn = max(maxn,count[dotc[n]]);
    for (int i=0; i<out[n].size(); i++) {
        dfs(out[n][i],count);//繼續探索其中一條路
    }
    count[dotc[n]]-=1;//全部路找完後要回推一格
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    int n,temp,a,b;
    set<int> s;
    map<int,int> m;
    vector<int> count(N,0);
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>temp;
        s.insert(temp);
        dotc[i] = temp;
    }
    for (int i=0; i<n-1; i++) {
        cin>>a>>b;
        out[a].push_back(b);
    }
    int num = 0;
    for (auto it = s.begin(); it != s.end(); it++) {
        m[*it] = num;
        num++;
    }
    for (int i=0; i<n; i++) {
        dotc[i] = m[dotc[i]];
    }
    dfs(0,count);
    cout<<maxn;
    return 0;
}