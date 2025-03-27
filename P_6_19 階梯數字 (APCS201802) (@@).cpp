#include <bits/stdc++.h>
#define LL long long
using namespace std;

//�o�D�n���إߤ@�ӻ��j���A�]dp[i][j]�����׬�j�B��i�}�Y������Ʀr�ơA���U�ӥL�����j���O�Adp[i][j] += dp[k][j-1] for all i<=k<=9
/*���U�ӭn����D�ذݪ��Ʀr�A���p��n=2789�A�⪺�B�J���O���A
i=0�Bj=4������Ʀr�ơAi=1�Bj=4������Ʀr�ơA���U�Ӧ]��2�}�Y��4��Ƥ��O�C�ӳ����i��
�A�ҥH�n���}�Ӻ�A����O2"2"�}�Y���T��ƪ�����Ʀr�ơA�@�����2"6"�}�Y���T��ƪ�����Ʀr�ơA����A���}��A�H������������̫�A�]��8"9"�U�@��S�Ʀr�F�A�ҥH�̫���׬��@���ɭԭn�⧹������}��*/
//���|�|��A�]����0�}�Y���ơA�i�H���̭���

LL dpp (int i,int j,vector<vector<LL>> &dp) {
    if (dp[i][j]!=-1) {
        return dp[i][j];
    } else {
        if (j==1) {
            return 1;
        }
        if (i==9) {
            return 1;
        }
        LL total2 = 0;
        for (int i2=i; i2<=9; i2++) {
            total2+=dpp(i2,j-1,dp);
        }
        return dp[i][j] = total2;
    }
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    LL total = 0;
    string n;
    cin>>n;
    vector<vector<LL>> dp(10,vector<LL> (19,-1));
    dp[0][1] = 0;
    int len = n.size();
    int last = 0;
    for (int i=0; i<n.size(); i++) {
        if (int(n[i])-48<last) {//�o�@��Ƥp��W�@��ƪ��ܴN�i�H���κ�F
            break;
        }
        if (len==1) {
            for (int i2=last; i2<=int(n[i])-48; i2++) {
                total+=dpp(i2,len,dp);
            }
            break;
        }
        for (int i2=last; i2<int(n[i])-48; i2++) {
            total+=dpp(i2,len,dp);
        }
        last = int(n[i])-48;
        len-=1;
    }
    cout<<total;
    return 0;
}
