#include <bits/stdc++.h>
using namespace std;

//�]dp[i]���ei�Ӱϰ쳣���л\��B�̫�@�Ӱ�a�x�]�bi���̤p����
//���Y��dp[i]=c[i]+dp[i-2k-1~i-1]���̤p��
//�]���n���̤p�ȡA�M�ᤣ�i��䤣�bi-2k-1~i-1�o�϶����A���M�N�|�S�����л\��
//�]���ĥΰj��]�϶����̤p�ȤӺC�F�A�ҥH�Τ@��deque���@�϶������̤p��

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;
    int line = 0;
    cin>>n>>k;
    vector<int> c(n+1,0);
    vector<int> dp(n+1,0);
    deque<int> m;
    for (int i=1; i<=n; i++) {
        cin>>c[i];
    }
    //��l��
    for (int i=1; i<=k+1; i++) {
        dp[i] = c[i];
        while(!m.empty()&&dp[m.back()]>=dp[i]) {
            m.pop_back();
        }
        m.push_back(i);
    }
    for (int i=k+2; i<=n; i++) {
        line = i-k-k-1;
        while(!m.empty()&&m.front()<line) {//�R���p��i-2k-1����
            m.pop_front();
        }
        if (!m.empty()) {
            dp[i] = c[i]+dp[m.front()];
        } else {
            dp[i] = c[i];
        }
        while(!m.empty()&&dp[m.back()]>=dp[i]) {//�p�Gdp[i]���Ȥp��e�����ȡA�N��e���N���|�O�̤p��
            m.pop_back();
        }
        m.push_back(i);
    }
    line = n-k;//���פ��|�u�X�{�bdp[n]�O�|�X�{�bn-k~n�o�϶��̭��A�]������\�����
    while(!m.empty()&&m.front()<line) {
        m.pop_front();
    }
    cout<<dp[m.front()];
    return 0;
}
