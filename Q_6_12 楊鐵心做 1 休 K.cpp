#include <bits/stdc++.h>
using namespace std;

//�]dp[i]���ei�Ѫ��̤j��Q�A���j���N�Odp[i] = max(dp[i-1],dp[i-k-1]+a[i]);
//dp[i-1]���Ѥ���
//dp[i-k-1]+a[i]���Ѱ��|�Ȩ줵�Ѫ����A���O�ek�ѳ����వ

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
