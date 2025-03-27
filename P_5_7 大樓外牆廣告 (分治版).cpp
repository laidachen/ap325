#include <bits/stdc++.h>
#define LL long long
using namespace std;

//用分治，左右兩邊遞迴，中間先用中心點的高度往左右擴張找在邊界區間內(l-r)的最大區間，之後再把高度調為小於中心高度的最高高度，看能不能擴展區間

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
    LL maxh = a[m];//不一定中間高度往旁邊擴張的最大區間就是最大面積，所以要降低高度找最大面積
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
        if (rr==r&&lr==l) {//做到兩邊邊界就停止
            break;
        }
        if (rr+1<=r&&lr-1>=l) {
            maxh = max(a[rr+1],a[lr-1]);//看有沒有出界，選最高的那邊
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
