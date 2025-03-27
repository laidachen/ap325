#include <bits/stdc++.h>
using namespace std;

//�w�qdp[i][j]�O�Ҥl�Wi����m��j����m���̤p���Υ��A���j���Odp[i][j] = dp[i][k]+dp[k][j]+p[j]-p[i] if i+1=j ���Τ��өҥH�O0�A�o�̪�k�Oi��j�϶��̭����@�Ӥ����I�A�]�������D�n�����@���I�A�ҥH�C�@���I���n�լݬ�
//top down�Τ@��dp�������O�_��L�F

int dpp(int i,int j,vector<int> &p,vector<vector<int>> &dp) {
    if (i+1==j) {
        return 0;
    }
    if (dp[i][j]!=-1) {
        return dp[i][j];
    } else {
        int mtotal = INT_MAX;
        for (int i2=i+1; i2<j; i2++) {
            mtotal = min(mtotal,dpp(i,i2,p,dp)+dpp(i2,j,p,dp));
        }
        return dp[i][j] = mtotal+p[j]-p[i];
    }
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,l;
    cin>>n>>l;
    vector<int> p(n+2,0);
    vector<vector<int>> dp(n+2,vector<int> (n+2,-1));
    for (int i=1; i<n+1; i++) {
        cin>>p[i];
    }
    p[n+1] = l;//��u�q���ڥ[�i�h
    cout<<dpp(0,n+1,p,dp);
    return 0;
}
