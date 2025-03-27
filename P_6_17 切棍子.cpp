#include <bits/stdc++.h>
using namespace std;

//定義dp[i][j]是棍子上i的位置到j的位置的最小切割本，遞迴式是dp[i][j] = dp[i][k]+dp[k][j]+p[j]-p[i] if i+1=j 不用切個所以是0，這裡的k是i到j區間裡面的一個切割點，因為不知道要切哪一個點，所以每一個點都要試看看
//top down用一個dp表格紀錄是否算過了

int dpp(int i,int j,vector<int> &p,vector<vector<int>> &dp) {
    if (i+1==j) {
        return 0;
    }
    if (dp[i][j]!=-1) {
        return dp[i][j];
    } else {
        int mtotal = INT_MAX;
        for (int i2=i+1; i2<j; i2++) {
            mtotal = min(mtotal,dpp(i,i2,p,dp)+dpp(i2,j,p,dp));
        }
        return dp[i][j] = mtotal+p[j]-p[i];
    }
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,l;
    cin>>n>>l;
    vector<int> p(n+2,0);
    vector<vector<int>> dp(n+2,vector<int> (n+2,-1));
    for (int i=1; i<n+1; i++) {
        cin>>p[i];
    }
    p[n+1] = l;//把線段尾巴加進去
    cout<<dpp(0,n+1,p,dp);
    return 0;
}
