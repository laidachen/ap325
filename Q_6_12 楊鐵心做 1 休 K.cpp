#include <bits/stdc++.h>
using namespace std;

//設dp[i]為前i天的最大獲利，遞迴式就是dp[i] = max(dp[i-1],dp[i-k-1]+a[i]);
//dp[i-1]今天不做
//dp[i-k-1]+a[i]今天做會賺到今天的錢，但是前k天都不能做

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> dp(n+1,0);
    vector<int> a(n+1,0);
    for (int i=1; i<=n; i++) {
        cin>>a[i];
    }
    for (int i=1; i<=k; i++) {
        dp[i] = max(dp[i-1],a[i]);
    }
    for (int i=k+1; i<=n; i++) {
        dp[i] = max(dp[i-1],dp[i-k-1]+a[i]);
    }
    cout<<dp[n];
    return 0;
}
