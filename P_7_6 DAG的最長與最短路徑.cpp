#include <bits/stdc++.h>
using namespace std;

int dpmin[10000] = {0};
int dpmax[10000] = {0};

//�]dpmin[i]��i�I��s�I���̵u�Z���A�L���ಾ���O�N�Odpmin[i] = min(dpmin[k]+w(k,i)) for �Ii���C�ӥ~�F�~(in-neighbor)�Adp[s] = 0;
//dpmax[i]�]�O�ΦP�˪�����
//�B�⪺���ǴN�O��X�o�i�Ϫ�topo����

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,s,t,g,e,w;
    int inde[10000] = {0};//�C���I��in-degree��
    int where = 0;
    cin>>n>>m;
    cin>>s>>t;
    vector<pair<int,int>> in[n];//�C���I��in neighbor�A���K��pair�O�s�v���A��K�᭱�i�H�����[
    vector<int> out[n];//�C���I��out neighbor
    vector<int> topo;
    queue<int> q;
    for (int i=0; i<m; i++) {
        cin>>g>>e>>w;
        in[e].push_back({g,w});
        out[g].push_back(e);
        inde[e]+=1;
    }
    //��Xtopo����
    for (int i=0; i<n; i++) {
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
    //��Xs�btopo���Ṋ̀������̡A�]���b�L����~�����i�H��
    for (int i=0; i<n; i++) {
        if (topo[i]==s) {
            where = i;
            break;
        }
        dpmin[topo[i]] = INT_MAX;//��ܤ��i���F
        dpmax[topo[i]] = INT_MIN;
    }
    //�}�ldp
    for (int i=where+1; i<topo.size(); i++) {
        int totalmin = INT_MAX;
        int totalmax = INT_MIN;
        for (int i2=0; i2<in[topo[i]].size(); i2++) {
            //�p�G���O���i��~��s�A���M�|�X���ܥ�
            if (dpmin[in[topo[i]][i2].first]<INT_MAX) {
                totalmin = min(totalmin,dpmin[in[topo[i]][i2].first]+in[topo[i]][i2].second);
            }
            if (totalmax,dpmax[in[topo[i]][i2].first]>INT_MIN) {
                totalmax = max(totalmax,dpmax[in[topo[i]][i2].first]+in[topo[i]][i2].second);
            }
        }
        dpmin[topo[i]] = totalmin;
        dpmax[topo[i]] = totalmax;
    }
    if (dpmin[t]==INT_MAX) {
        cout<<"No path"<<endl;
    } else {
        cout<<dpmin[t]<<endl;
    }
    if (dpmax[t]==INT_MIN) {
        cout<<"No path"<<endl;
    } else {
        cout<<dpmax[t]<<endl;
    }
    return 0;
}
