#include <bits/stdc++.h>
using namespace std;

//bottom up
//遞迴的關係式是c[i] = c[i]+min(c[i-1],c[i-2]) i>2
//因為最後一步走到i一定是走兩階或是一階，位置會在i-2或i-1

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,temp;
    int a[100001];
    int dp[100001] = {0};
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>temp;
        a[i] = temp;
    }
    dp[1] = a[1];
    dp[2] = a[2];
    for (int i=3; i<=n; i++) {
        dp[i] = a[i]+min(dp[i-1],dp[i-2]);
    }
    cout<<dp[n];
    return 0;
}
