#include <bits/stdc++.h>
using namespace std;


//�p�G�Ψ���o�ni�B���I�������k���A�B����ǰe�L�ᨺ���I�S�Q�X�ݹL�A�N�Oi+1�B���I�A�N����bfs i-1�N���X�ݧ��F�A�M��b�X��i�N�ɥL���F�~�S�Q�X�ݹL�A�N�Oi+1�N��
//�ҥH��bfs�䲾�ʤ@���|�쪺�I�A����[�J�M��A�~��䲾�ʨ⦸�|�쪺�I�A�H����������M��̬O�Ū�
//�M���٭n�p���ʨ�o���I�O���O�Ĥ@���J��A���O���ܴN�N��e������n����
//�٭n�ˬd���k���ʷ|���|�V�ɡA���|�V�ɤ]�n��L�ǰe�I�|���|�V��

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,p,l,r;
    cin>>n>>p>>l>>r;
    vector<int> map(n,0);
    vector<int> dis(n,-1);
    vector<int> visit(n,0);
    for (int i=0; i<n; i++) {
        cin>>map[i];
    }
    queue<int> q;
    visit[0] = 1;
    dis[0] = 0;
    q.push(0);
    while(!q.empty()) {
        if (q.front()-l>=0) {
            if (map[q.front()-l]<n&&map[q.front()-l]>=0) {
                if (visit[map[q.front()-l]]==0) {
                    visit[map[q.front()-l]] = 1;
                    dis[map[q.front()-l]] = dis[q.front()]+1;
                    q.push(map[q.front()-l]);
                    if (map[q.front()-l]==p) {
                        break;
                    }
                }
            }
        }
        if (q.front()+r<n) {
            if (map[q.front()+r]<n&&map[q.front()+r]>=0) {
                if (visit[map[q.front()+r]]==0) {
                    visit[map[q.front()+r]] = 1;
                    dis[map[q.front()+r]] = dis[q.front()]+1;
                    q.push(map[q.front()+r]);
                    if (map[q.front()+r]==p) {
                        break;
                    }
                }
            }
        }
        q.pop();
    }
    if (p<n&&p>=0) {
        cout<<dis[p];
    } else {
        cout<<-1;
    }
    return 0;
}
