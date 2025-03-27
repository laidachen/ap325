#include <bits/stdc++.h>
using namespace std;

//����Xtopo�����ٯ���D��
//�]needtime[n]����n�o�u�@�[�e�����L���̤p�ɶ��Aneedtime[n]�N�On��in neighbor�Ҫ�ɶ����̤j�ȥ[�W�ۤv�A�]����b��L�a�褣�|��������a�~�వn������
//�b�⪺�ɭԭn�p��@�ӳ̤j��now�A�ΨӰO���ثe�ɶ����̤j�ȡA���p���W�L�o�̤j�ȴN�n��s�A�p�󪺸ܴN�N��u�@��b�o�ɶ�������
//�����٭n�s�@�ӧ����ɶ��L�諸�u�@�A�p�G�o�̨C�Ӥu�@���᩵�A�����ɶ��N�|�ܪ��A�ҥH���O����u�@
//�]���i�঳�ܦh�ӧ����ɶ����@�˪����p�A�ҥH�n�s�_�ӨC�ӧ����ɶ��@�˥L������u�@�A�̫�A��SET�L�o���N�n�F

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,g,e;
    int now = 0;
    int needtime[10001] = {0};
    int inde[10001] = {0};
    cin>>n>>m;
    vector<int> in[n+1];
    vector<int> out[n+1];
    vector<int> a[n+1];
    vector<int> topo;
    vector<int> time(n+1,0);
    vector<int> again;
    vector<int> againnow;
    set<int> s;
    queue<int> q;
    for (int i=1; i<=n; i++) {
        cin>>time[i];
    }
    for (int i=0; i<m; i++) {
        cin>>g>>e;
        out[g].push_back(e);
        in[e].push_back(g);
        inde[e]+=1;
    }
    for (int i=1; i<=n; i++) {
        if (inde[i]==0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        for (int i=0; i<out[q.front()].size(); i++) {
            inde[out[q.front()][i]]-=1;
            if (inde[out[q.front()][i]]==0) {
                q.push(out[q.front()][i]);
            }
        }
        topo.push_back(q.front());
        q.pop();
    }
    for (int i=0; i<topo.size(); i++) {
        if (in[topo[i]].size()==0) {
            needtime[topo[i]] = time[topo[i]];
            if (needtime[now]<needtime[topo[i]]) {
                now = topo[i];
            }
            a[topo[i]].push_back(topo[i]);
        } else {
            int maxn = INT_MIN;
            int where = 0;
            for (int i2=0; i2<in[topo[i]].size(); i2++) {
                //�]���i��@�˩ҥH�]�n�����[�i��
                if (needtime[in[topo[i]][i2]]==maxn) {
                    again.push_back(in[topo[i]][i2]);
                }
                if (needtime[in[topo[i]][i2]]>maxn) {
                    maxn = needtime[in[topo[i]][i2]];
                    where = in[topo[i]][i2];
                    again.clear();
                    again.push_back(where);
                }
            }
            needtime[topo[i]] = needtime[where]+time[topo[i]];
            for (int i2=0; i2<again.size(); i2++) {
                for (int i3=0; i3<a[again[i2]].size(); i3++) {
                    a[topo[i]].push_back(a[again[i2]][i3]);
                }
            }
            again.clear();
            a[topo[i]].push_back(topo[i]);
            if (needtime[topo[i]]==needtime[now]) {
                againnow.push_back(topo[i]);
            }
            if (needtime[topo[i]]>needtime[now]) {
                now = topo[i];
                againnow.clear();
                againnow.push_back(now);
            }
        }
    }
    cout<<needtime[now]<<endl;
    for (int i=0; i<againnow.size(); i++) {
        for (int i2=0; i2<a[againnow[i]].size(); i2++) {
            s.insert(a[againnow[i]][i2]);
        }
    }
    for (auto it=s.begin(); it!=s.end(); it++) {
        cout<<*it<<" ";
    }
    return 0;
}
