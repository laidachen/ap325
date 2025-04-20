#include <bits/stdc++.h>
#define N 50000
using namespace std;
//如果要每個點都探訪到然後要回到原點，在樹上每條邊都要走兩次
//但是今天只要探訪完所有點就能停下來，所以我可以不用再從最遠的路走回來，所以可以扣掉，這個最遠的路就是樹的直徑，然後這裡每條路都有權重，所以要找的是值最大的直徑
vector<pair<int,int>> out[N];
int maxl = 0;
//dfs會先探訪他的孩子，然後加上這條路的邊長，接著探訪完他的孩子後就找出第一大跟第二大，最後回傳第一大的長度
int dfs(int n,int parent) {
    vector<int> temp;
    for (int i=0; i<out[n].size(); i++) {
        if (out[n][i].first!=parent) {
            temp.push_back(dfs(out[n][i].first,n)+out[n][i].second);
        }
    }
    if (temp.size()!=0) {
        sort(temp.begin(),temp.end());
        maxl = max(maxl,temp[temp.size()-1]+temp[temp.size()-2]);
        return temp[temp.size()-1];
    } else {
        return 0;
    }
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,a,b,w;
    int total = 0;
    cin>>n;
    for (int i=0; i<n-1; i++) {
        cin>>a>>b>>w;
        total+=w*2;
        out[a].push_back({b,w});
        out[b].push_back({a,w});
    }
    dfs(0,-1);
    cout<<total-maxl;
    return 0;
}