#include <bits/stdc++.h>
#define LL long long
using namespace std;

//�]dp[i]��i�o���R�B�O��O�̤p���A�o�O���j���Y��dp[i] = a[i]+min(min(dp[i-1],dp[i-2]),dp[i-3])�A�]�������D���̦����̤p�A�ӥB���|i-1,i-2,i-3���S�D�A���M�N���|�������Q�ʱ�

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
    cout<<min(dp[n],dp[n-1]);//�i��O�ثe�o�@���A�άO�e�@���A�]�����]�m�ҥHn�]�|�Q�ʱ���
    return 0;
}
