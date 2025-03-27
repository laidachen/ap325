#include <bits/stdc++.h>
using namespace std;
#define MAX 900000000

//�]�wdp[i][seat]���ei�ӫȤH�B�h����>=seat�ƪ��̤p��
//�n�Ҽ{�O�_�n�h�o�ӫȤH
//�p�G���h�N�N��n���e�@�쪺seat���pdp[i][seat] = dp[i-1][seat]
//�p�G�n�h�N�N��n���e�@�쪺seat-f[i]�����p�A�M��i��O�t�ƩҥH��n0���

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
    vector<vector<int>> dp(101,vector<int>(goal+1,0));//�]�w�@�ӤG���}�C�j�p101�̭���j�p��goal+1���@���}�C�A����int dp[101][goal+1]
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
