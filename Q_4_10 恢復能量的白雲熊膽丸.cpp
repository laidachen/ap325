#include <bits/stdc++.h>
using namespace std;

//�������O�ﵪ�ק@�G���j�A�M��C�����ݳܤ������Ʀ��S���p��̦h�ܤ����ơA�p�G���N��o�Ȥj��ؼЪ��ȡA�ҥH�k��n-1

int ok(long long mid,vector<int> guan,int m) {
    int total = 0;
    int f = mid;
    for (int i=0; i<guan.size(); i++) {
        if (f<guan[i]) {
            total++;
            f = mid;
            if (f<guan[i]) {//�w���ܤ��٬O�S�L
                return 0;
            }
            f -= guan[i];
        } else {
            f -= guan[i];
        }
    }
    if (total<=m) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    long long ans = 0;
    int n,m,temp;
    vector<int> guan;
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        cin>>temp;
        guan.push_back(temp);
    }
    long long r = 1000000000;
    long long l = 0;
    while(l<=r) {
        long long mid = (r+l)/2;
        if (ok(mid,guan,m)) {
            r = mid-1;
            ans = mid;
        } else {
            l = mid+1;
        }
    }
    cout<<ans;
    return 0;
}
