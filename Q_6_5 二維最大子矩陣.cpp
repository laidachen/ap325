#include <bits/stdc++.h>
using namespace std;

//�D�n�Τ��ep-4-13���d����k�A����]�@�ө���@�ӳ̤W���A�M��Τ@�Ӥ@���}�C��ܱq���[�쩳���ȡA����Υd����k�A����s�ɡA���N�n�@�����W��@�M��򰪤@�ˡA�o�ˤ~����������M

void add(vector<int> &total,int a[201][201],int top,int m,int n) {//vector�~��ǰѦ�
    for (int i=1; i<=n; i++) {
        for (int i2=m; i2>=top; i2--) {
            total[i]+=a[i2][i];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int m,n,temp;
    int a[201][201] = {0};
    vector<int> total(201,0);
    int maxn = -1*4*pow(10,8);
    cin>>m>>n;
    for (int i=1; i<=m; i++) {
        for (int i2=1; i2<=n; i2++) {
            cin>>temp;
            a[i][i2] = temp;
        }
    }
    for (int top=1; top<=m; top++) {//��
        add(total,a,top,m,n);//�q���[�쩳���禡
        for (int down=m; down>=top; down--) {//��
            int now = total[1];
            maxn = max(now,maxn);
            for (int i=2; i<=n; i++) {//�d����k
                if (total[i]+now>=total[i]) {
                    now+=total[i];
                } else {
                    now = total[i];
                }
                maxn = max(now,maxn);
            }
            for (int i=1; i<=n; i++) {
                total[i]-=a[down][i];
            }
        }
    }
    cout<<maxn;
    return 0;
}
