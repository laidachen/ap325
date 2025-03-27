#include <bits/stdc++.h>
using namespace std;

//�]dp[i][j]���ei�Ӫ��~�B���q���W�Lj���̤j�Q�q
//�|���T�ت��pw[i]>j�A�N���i��[���i��dp[i][j] = dp[i-1][j];
//�άOw[i]=<j���O���[�i��dp[i][j] = dp[i-1][j];
//�άO�[�i�ӥB�e�@���D�����q���W�Lj-w[i]�Adp[i][j] = dp[i-1][j-w[i]]+p[i];

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int dp[101][100001] = {0};//�}�C�}�Ӥj�sĶ��������
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



