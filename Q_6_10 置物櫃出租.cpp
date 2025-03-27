#include <bits/stdc++.h>
using namespace std;
#define MAX 900000000

//設定dp[i][seat]為前i個客人且退滿足>=seat數的最小值
//要考慮是否要退這個客人
//如果不退就代表要取前一位的seat狀況dp[i][seat] = dp[i-1][seat]
//如果要退就代表要取前一位的seat-f[i]的狀況，然後可能是負數所以跟要0比較

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,s,temp;
    int sum = 0;
    cin>>n>>m>>s;
    int f[101] = {0};
    for (int i=1; i<=n; i++) {
        cin>>temp;
        f[i] = temp;
        sum+=temp;
    }
    int goal = s-(m-sum);
    vector<vector<int>> dp(101,vector<int>(goal+1,0));//設定一個二維陣列大小101裡面塞大小為goal+1的一維陣列，等於int dp[101][goal+1]
    for (int i=1; i<=goal; i++) {
        dp[0][i] = MAX;
    }
    for (int i=1; i<=n; i++) {
        for (int seat=1; seat<=goal; seat++) {
            dp[i][seat] = min(dp[i-1][seat],dp[i-1][max(0,seat-f[i])]+f[i]);
            if (dp[i][seat]<seat) {
                dp[i][seat] = MAX;
            }
        }
    }
    cout<<dp[n][goal];
    return 0;
}
