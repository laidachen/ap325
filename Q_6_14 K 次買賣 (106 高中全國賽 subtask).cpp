#include <bits/stdc++.h>
using namespace std;

//�o�D�]dp[i][j]����i�ѫe�A���X�Lj���R�檺�̤j��Q�A���U�Ӧ���ӱ��p
//��Xp[i]�A�]�������Dp[i]��e�����ѽ�X�|���̤j��Q�A�ҥH�L���e���n�չL�@�Mdp[i][j] = max(p[i]-p[t]+dp[t-1][j-1]) t<i
//����X�A�N�Odp[i][j] = dp[i-1][j]
//��Ө��̤j�N�n�F
//�p�G�n����t<i�o�ӽd��A�����״N�|�OO(knn)�A�ҥH�ں��@�@���ܼơA�C�����|��s�@��dp[d-1][b-1]-p[d]�A�ݭ��@�ӭȬO�̤j���N��s�W�h�A����C����s���u�n��p[i]+�����ܼơA�N�|����p[i]-p[d]+dp[d-1][b-1]-p[d]

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;

    cin>>n>>k;
    vector<int> p(n+1,0);
    vector<vector<int>> dp(n+1,vector<int> (k+1,0));
    for (int i=1; i<=n; i++) {
        cin>>p[i];
    }
    for (int b=1; b<=k; b++) {
        int dm = dp[0][b-1]-p[1];
        for (int d=1; d<=n; d++) {
            dp[d][b] = max(p[d]+dm,dp[d-1][b]);
            dm = max(dm,dp[d-1][b-1]-p[d]);
        }
    }
    cout<<dp[n][k];
    return 0;
}

