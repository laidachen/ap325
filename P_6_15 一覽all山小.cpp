#include <bits/stdc++.h>
using namespace std;

//�o�D���]dp[i]��i�I�O�̫�B���e��LIS�ơA���Y���Odp[i] = max(dp[j])+1 j<i a[j]<a[i]
//���p�C�����n�^�h�]�@���e���A�����׷|�OO(n^2)�AŪ��C��j<i�Ba[j]>=a[i]�Bdp[j]<=dp[i]�A�N�N����j�S����
//�ҥH�i�H�Ф@�Ӱ}�C�ΨӦs����׬�L���̤p�i��ȡA�����C�Ӧr�����G���j�A�]���O���W���ƦC�A���׶V�����i��̤p�ȷ|�V�p�A����N�n�B�z�F�A���צb�}�C�̫᪺�a��

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    vector<int> l(1,0);
    for (int i=1; i<=n; i++) {
        cin>>a[i];
    }
    for (int i=1; i<=n; i++) {
        int where = 0;
        for (int dis=l.size(); dis>0; dis=dis/2) {
            while (where+dis<l.size()&&a[i]>l[dis+where]) {
                where+=dis;
            }
        }
        if (where+1==l.size()) {
            l.push_back(a[i]);
        } else {
            if (a[i]<l[where+1]) {
                l[where+1] = a[i];
            }
        }
    }
    cout<<l.size()-1;
    return 0;
}
