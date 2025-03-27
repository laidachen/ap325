#include <bits/stdc++.h>
using namespace std;

//top down
//設f(g[i][j])為到這關的成本j==1，那f(g[i][j])=abs(g[i][j]-g[n-1][j])+f(g[n-1][j]) with abs(g[i][j]-g[n-1][j-1])+f(g[n-1][j-1])
//那要到g[i][j]的最小成本就是 minf(g[i][j])=min(abs(g[i][j]-g[n-1][j])+minf(g[n-1][j]),abs(g[i][j]-g[n-1][j-1])+minf(g[n-1][j-1]))
//一開始兩關的最小成本就是自己-t的絕對值

int a[100001][2] = {0};
int dp[100001][2] = {0};
int dpp(int n,int j) {
    if (dp[n][j]>0) {
        return dp[n][j];
    } else {
        if (j==0) {
            dp[n][j] = min((abs(a[n][j]-a[n-1][j])+dpp(n-1,j)),(abs(a[n][j]-a[n-1][j+1])+dpp(n-1,j+1)));
            return dp[n][j];
        } else {
            dp[n][j] = min((abs(a[n][j]-a[n-1][j])+dpp(n-1,j)),(abs(a[n][j]-a[n-1][j-1])+dpp(n-1,j-1)));
            return dp[n][j];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,temp,temp2,t;
    cin>>n>>t;
    for (int i=1; i<=n; i++) {
        cin>>temp>>temp2;
        a[i][0] = temp;
        a[i][1] = temp2;
    }
    dp[1][0] = abs(t-a[1][0]);
    dp[1][1] = abs(t-a[1][1]);
    cout<<min(dpp(n,0),dpp(n,1));
    return 0;
}
