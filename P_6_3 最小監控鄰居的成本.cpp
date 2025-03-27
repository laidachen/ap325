#include <bits/stdc++.h>
#define LL long long
using namespace std;

//砞dp[i]i硂Τ禦琌禣程硂琌患癹闽玒Αdp[i] = a[i]+min(min(dp[i-1],dp[i-2]),dp[i-3])ぃ笵柑Θセ程τぃ穦i-1,i-2,i-3常⊿珼ぃ礛碞ぃ穦场常砆菏北

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,temp;
    int a[100001];
    LL dp[100001];
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>temp;
        a[i] = temp;
    }
    dp[1] = a[1];
    dp[2] = a[2];
    dp[3] = a[3]+min(dp[1],dp[2]);
    for (int i=4; i<=n; i++) {
        dp[i] = a[i]+min(min(dp[i-1],dp[i-2]),dp[i-3]);
    }
    cout<<min(dp[n],dp[n-1]);//琌ヘ玡硂兜┪琌玡兜Τ砞竚┮n穦砆菏北
    return 0;
}
