#include <bits/stdc++.h>
using namespace std;

//�]dp[i][j]��s1��i�Ӧr�����e�Ps2��j�Ӧr�����e��LCS��
//�|����ت��p
//s1[i] == s2[j]�A�o�ɭԭn�D�Xdp[i-1][j-2]�A+1�A�]���L�̦r���@��
//s1[i] != s2[j]�A�o�ɭԥN��ܤ֦��@�Ӧr�����LCS�O�S�Ϊ��A�ҥH�D�Xdp[i-1][i2]�Adp[i][i2-1]�Adp[i-1][i2-1]��j�p�N�n�F
//��l����Odp[i][0]��dp[0][j]�A�]�����@�ӬO�Ŧr��A�ҥHLCS�O0

int main(void) {
    string s1,s2;
    int dp[501][501] = {0};
    cin>>s1;
    cin>>s2;
    for (int i=1; i<=s1.size(); i++) {
        for (int i2=1; i2<=s2.size(); i2++) {
            if (s1[i-1]==s2[i2-1]) {
                dp[i][i2] = dp[i-1][i2-1]+1;
            } else {
                dp[i][i2] = max(max(dp[i-1][i2],dp[i][i2-1]),dp[i-1][i2-1]);
            }
        }
    }
    cout<<dp[s1.size()][s2.size()];
    return 0;
}
