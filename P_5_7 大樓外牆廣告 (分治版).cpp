#include <bits/stdc++.h>
#define LL long long
using namespace std;

//�Τ��v�A���k���仼�j�A�������Τ����I�����ש����k�X�i��b��ɰ϶���(l-r)���̤j�϶��A����A�Ⱚ�׽լ��p�󤤤߰��ת��̰����סA�ݯण���X�i�϶�

LL dac(vector<LL> &a,int l,int r) {
    if (l==r) {
        return a[l];
    }
    if (l+1==r) {
        if (a[l]>=a[r]) {
            return a[r]*2;
        } else {
            return a[l]*2;
        }
    }
    int m = (r+l)/2;
    LL lmax = dac(a,l,m);
    LL rmax = dac(a,m+1,r);
    LL smax = max(lmax,rmax);
    LL amax = 0;
    int lr = m;
    int rr = m;
    LL maxh = a[m];//���@�w�������ש������X�i���̤j�϶��N�O�̤j���n�A�ҥH�n���C���ק�̤j���n
    while (true) {
        while(lr-1>=l&&a[lr-1]>=maxh) {
            lr--;
        }
        while(rr+1<=r&&a[rr+1]>=maxh) {
            rr++;
        }
        if (maxh*(rr-lr+1)>amax) {
            amax = maxh*(rr-lr+1);
        }
        if (rr==r&&lr==l) {//���������ɴN����
            break;
        }
        if (rr+1<=r&&lr-1>=l) {
            maxh = max(a[rr+1],a[lr-1]);//�ݦ��S���X�ɡA��̰�������
        } else if (rr+1<=r) {
            maxh = a[rr+1];
        } else {
            maxh = a[lr-1];
        }
    }
    return max(smax,amax);
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    LL temp;
    vector<LL> a;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>temp;
        a.push_back(temp);
    }
    cout<<dac(a,0,n-1);
    return 0;
}
