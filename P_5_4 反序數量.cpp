#include <bits/stdc++.h>
#define LL long long
using namespace std;

//����Q�k�O�Τ��v�t��k�A�f�ƹ�i��|�b���b��A�άO�k�b��A�άO��󤤶���k��

void dac(LL a[],int l,int r,LL &count) {
    if (l == r) {
        return;//��void�S���ƪ��n�[return
    }
    if (l+1==r && a[l]>a[r]) {
        count+=1;
        return;
    }
    int m = (r+l)/2;
    dac(a,l,m,count);
    dac(a,m+1,r,count);
    sort(a+m+1,a+r+1);//sort�n�Ƨǰ϶����Ϊk�Osort(�_�I,���I��@��)�A���o�˷|�Ƨ�[m+1,r]
    for (int i=l; i<=m; i++) {
        int where = m;
        for (int dis=r-m; dis>0; dis=dis/2) {//�ΤG���j��̤j���f�ƹ�
            while(where+dis<=r&&a[i]>a[where+dis]) {
                where+=dis;
            }
        }
        if (where==m) {
            continue;
        } else {
            count+=(where-m);
        }
    }

}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    LL temp;
    LL count = 0;
    LL a[100000];
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>temp;
        a[i] = temp;
    }
    dac(a,0,n-1,count);
    cout<<count;

    return 0;
}
