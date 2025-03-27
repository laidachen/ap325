#include <bits/stdc++.h>
using namespace std;

//�o�D�]dp[i]�����Ii�Z���̪����l�]���Z���A���L�����j���N�Odp[i] = max(dp[k])+1�Ak�O�o���I��out neighbor�N�O�L���Ĥl�A�M���٭n�[�@�A�]�����W�@�B
//���U�ӭn���@�ө��W���X�����ǡA�N����topo���Ǫ��@�k�A��S�Ĥl������ӡA�����L��parent���Ĥl�Ʀ��@�A�p�G�L�Ĥl�Ƶ���0�A�N��L�[�iqueue��
//�N��bottom up�W�h�F

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,temp;
    cin>>n;
    vector<int> in[n+1];
    vector<int> out[n+1];
    vector<int> child(n+1,0);
    queue<int> q;
    vector<int> topo;
    vector<int> dp(n+1,0);
    for (int i=1; i<=n; i++) {
        int k;
        cin>>k;
        child[i] = k;
        for (int i2=0; i2<k; i2++) {
            cin>>temp;
            in[temp].push_back(i);
            out[i].push_back(temp);
        }
    }
    for (int i=1; i<=n; i++) {
        if (child[i]==0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        for (int i=0; i<in[q.front()].size(); i++) {
            child[in[q.front()][i]]-=1;
            if (child[in[q.front()][i]]==0) {
                q.push(in[q.front()][i]);
            }
        }
        topo.push_back(q.front());
        q.pop();
    }
    cout<<topo[topo.size()-1]<<endl;
    int total = 0;
    for (int i=0; i<topo.size(); i++) {
        if (out[topo[i]].size()==0) {
            continue;
        }
        int maxn = 0;
        for (int i2=0; i2<out[topo[i]].size(); i2++) {
            maxn = max(maxn,dp[out[topo[i]][i2]]);
        }
        dp[topo[i]] = maxn+1;
        total+=maxn+1;
    }
    cout<<total;
    return 0;
}
