#include <bits/stdc++.h>
using namespace std;

/*設f(m,n)為到m,n的最大總和，因為最後一步可能是從上往下或是從左到右
，所以整個遞迴式是f(m,n) = max(f(m-1,n),f(m,n-1))+a[m][n]*/

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int m,n,temp;
    int a[201][201];
    int dp[201][201];
    cin>>m>>n;
    for (int i=1;i <=m; i++) {
        for (int i2=1; i2<=n; i2++) {
            cin>>temp;
            a[i][i2] = temp;
        }
    }
    dp[1][1] = a[1][1];
    //初始條件
    //因為只能由上往下，沒有左邊
    for (int i=2; i<=m; i++) {
        dp[i][1] = dp[i-1][1]+a[i][1];
    }
    //因為只能由左到右，沒有上面
    for (int i=2; i<=n; i++) {
        dp[1][i] = dp[1][i-1]+a[1][i];
    }
    for (int i=2; i<=m; i++) {
        for (int i2=2; i2<=n; i2++) {
            dp[i][i2] = a[i][i2]+max(dp[i-1][i2],dp[i][i2-1]);
        }
    }
    cout<<dp[m][n];
    return 0;
}
