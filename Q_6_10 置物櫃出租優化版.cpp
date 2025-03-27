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
    //�u�ʼƲ��u��
    vector<int> dp(goal+1,0);
    vector<int> up(goal+1,0);
    for (int i=1; i<=goal; i++) {
        up[i] = MAX;
    }
    for (int i=1; i<=n; i++) {
        for (int seat=1; seat<=goal; seat++) {
            dp[seat] = min(up[seat],up[max(0,seat-f[i])]+f[i]);
            if (dp[seat]<seat) {
                dp[seat] = MAX;
            }
        }
        up = dp;
    }
    cout<<dp[goal];
    return 0;
}
