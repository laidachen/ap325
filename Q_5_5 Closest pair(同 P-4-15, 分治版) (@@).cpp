#include <bits/stdc++.h>
#define LL long long
using namespace std;

//�o�D�ڪ��Ѫk�O���v�[�ưʵ����[�G���j
//����x���Ƨǫ������b�A���k��λ��j�ѨM�A�����ηưʵ����[�G���j


bool compare (vector<LL> a,vector<LL> b) {
    return a[1]<b[1];
}

LL dac(vector<vector<LL>> &a,int l,int r) {
    if (l==r) {
        return pow(10,16);
    }
    if (l+1==r) {
        return abs(a[l][0]-a[r][0])+abs(a[l][1]-a[r][1]);
    }
    int m = (r+l)/2;
    LL lmin = dac(a,l,m);
    LL rmin = dac(a,m+1,r);
    LL smin = min(lmin,rmin);
    int right = m+1;
    int fr = m+1;
    LL mmin = pow(10,16);
    //�ηưʵ�����d��
    for (int i=l; i<=m; i++) {//i+1��x���ܤj�~�੹�e��
        while(right+1<=r&&abs(a[right+1][0]-a[i][0])<=smin) {//�p�Ga[right][0]-a[i][0]>smin�A�N�N��L�`�M�@�w�j��smin�A�ҥH���κ�
            right++;
            if ((abs(a[right][0]-a[i][0])+abs(a[right][1]-a[i][1]))<mmin) {
                mmin = abs(a[right][0]-a[i][0])+abs(a[right][1]-a[i][1]);
            }
        }
    }
    vector<vector<LL>> b(a.begin()+m+1,a.begin()+right+1);//�^��a�����q�Ф@�ӷs��vector
    sort(b.begin(),b.end(),compare);
    //�ΤG���j��y�ȳ̬۪񪺦�m�A�����e�ưʵ����S�]�쪺�����ɤW��
    for (int i=l; i<=m; i++) {
        int fr = 0;
        for (int dis=b.size(); dis>0; dis=dis/2) {
            while (fr+dis<=b.size()-1&&b[fr+dis][1]<a[i][1]) {
                fr+=dis;
            }
        }

        if ((abs(b[fr][0]-a[i][0])+abs(b[fr][1]-a[i][1]))<mmin) {//�o�̨�ꤣ�κެO�_��x�۴�|�j��smin�A�]���p��N�|���W�h�F
            mmin = abs(b[fr][0]-a[i][0])+abs(b[fr][1]-a[i][1]);
        }
        if (fr+1<=b.size()-1) {
            if ((abs(b[fr+1][0]-a[i][0])+abs(b[fr+1][1]-a[i][1]))<mmin) {
                mmin = abs(b[fr+1][0]-a[i][0])+abs(b[fr+1][1]-a[i][1]);
            }
        }
    }
    return min(smin,mmin);
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    LL temp,temp2;
    vector<vector<LL>> a;
    vector<LL> add;
    cin>>n;
    for (int i=0; i<n; i++) {
        for (int i2=0; i2<2; i2++) {
            cin>>temp;
            add.push_back(temp);
        }
        a.push_back(add);
        add.clear();
    }
    sort(a.begin(),a.end());
    cout<<dac(a,0,n-1);
    return 0;
}
