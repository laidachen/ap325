#include <bits/stdc++.h>
using namespace std;

//bottom up
//���j�����Y���Oc[i] = c[i]+min(c[i-1],c[i-2]) i>2
//�]���̫�@�B����i�@�w�O���ⶥ�άO�@���A��m�|�bi-2��i-1

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
