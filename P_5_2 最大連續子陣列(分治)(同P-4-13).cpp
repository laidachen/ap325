#include <bits/stdc++.h>
using namespace std;
#define LL long long

//���v������O�����A�M�����U�ۥλ��j�ѨM���D��̫�X��
//�o�D���Ѫk�O����k��϶��A�̤j�ȥi��b����άO�k��A�άO�����A�ҥH�����]�n�Ҽ{

LL dac(vector<LL> &a,LL l,LL r) {//�p�G�S���ǰѦҨC���I�s�@���禡���|�ƻs�@��vector�A�o�N�O�ɭPTLE�����D�A�ǰѦҴN�O�����եέ쥻��a
    if (l+1==r) {//��̩��n�^�ǭ�
        return max(a[l],a[r]);
    }
    if (l==r) {
        return a[l];
    }
    LL m = (r+l)/2;
    LL largest = max(dac(a,l,m),dac(a,m+1,r));//������k��ä�j�p

    LL total = 0;
    LL maxls = 0;
    LL maxrs = 0;
    for (LL i=m; i>=l; i--) {
        total+=a[i];
        if (total>maxls) {
            maxls = total;
        }
    }
    total = 0;
    for (LL i=m+1; i<=r; i++) {
        total+=a[i];
        if (total>maxrs) {
            maxrs = total;
        }
    }
    LL maxm = maxls+maxrs;
    return max(maxm,largest);//�򤤶����
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    LL n,temp;
    vector<LL> a;
    cin>>n;
    for (LL i=0; i<n; i++) {
        cin>>temp;
        a.push_back(temp);
    }
    LL vaule = dac(a,0,n-1);
    if (vaule<0) {
        cout<<0;
    } else {
        cout<<vaule;
    }
    return 0;
}
