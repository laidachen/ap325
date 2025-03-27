#include <bits/stdc++.h>
using namespace std;

//設dp[i][j]為前i個物品且重量不超過j的最大利益
//會有三種狀況w[i]>j，代表不可能加不進來dp[i][j] = dp[i-1][j];
//或是w[i]=<j但是不加進來dp[i][j] = dp[i-1][j];
//或是加進來且前一項挑的重量不超過j-w[i]，dp[i][j] = dp[i-1][j-w[i]]+p[i];

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int dp[101][100001] = {0};//陣列開太大編譯器不給用
    int w[101] = {0};
    int p[101] = {0};
    int n,temp,maxw;
    cin>>n>>maxw;
    for (int i=1; i<=n; i++) {
        cin>>temp;
        w[i] = temp;
    }
    for (int i=1; i<=n; i++) {
        cin>>temp;
        p[i] = temp;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=maxw; j++) {
            if (w[i]>j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j],(p[i]+dp[i-1][j-w[i]]));
            }
        }
    }
    cout<<dp[n][maxw];
    return 0;
}



