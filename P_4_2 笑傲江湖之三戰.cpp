#include <bits/stdc++.h>
using namespace std;

/*�Ѫk�O��X�ڤ�����O�̱���B�W�L�Ĥ�䤤�@�H�����O�����@�ӡA
��������O�����ƧǡA�N�|�q�̤p���}�l��A�]���u�n�ؼмĤH�����O�j��ڤ誺�����O�A
������ĤH�����O�V�j�A���H�����O�]�S�ΡA
�ҥH�i�H���ƧǤ���Τ@�ګ��w�]��̱���B���W�L����m*/

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,temp;
    int point = -1;
    int win = 0;
    vector<int> enemy;
    vector<int> myside;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>temp;
        enemy.push_back(temp);
    }
    for (int i=0; i<n; i++) {
        cin>>temp;
        myside.push_back(temp);
    }
    sort(enemy.begin(),enemy.end());
    sort(myside.begin(),myside.end());
    for (int i=0; i<n; i++) {
        while(point+1<n&&myside[point+1]<=enemy[i]) {
            point++;
        }
        if (point+1==n) {
            break;
        } else {
            point++;
            win++;
        }
    }
    cout<<win;
    return 0;
}
