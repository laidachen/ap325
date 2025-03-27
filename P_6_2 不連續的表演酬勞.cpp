#include <bits/stdc++.h>
using namespace std;

//top down
//�o�@�D�����j���Y���Odp[i] = max(d[i]+dp[i-2],dp[i-1]) i>2
//�Ҽ{�ݬݦp�G���Ѥ����A�N�N��Q�ѭn���A�άO���Ѱ��A�N��Q�Ѥ��వ�A�O�n�[�e�Ѫ��̤j��q�A��Ӥ�j�p�N�n
//bottom up���g�k�O��X�p�ⶶ�ǫ�ΰj����X��
//top down���g�k�O�����@�Ӫ���λ��j���g�k�A�M���o��榳�S����L�A�p�G��L�N�^�ǡA���M�N��@�M�ç�s�W�h

int d[100001] = {0};
int dp[100001] = {0};
int maxincome(int n) {
    if (dp[n]>0) {
        return dp[n];
    } else {
        dp[n] = max(maxincome(n-1),d[n]+maxincome(n-2));
        return dp[n];
    }
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,temp;
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>temp;
        d[i]= temp;
    }
    dp[1] = d[1];
    dp[2] = max(d[1],d[2]);
    cout<<maxincome(n);
    return 0;
}
