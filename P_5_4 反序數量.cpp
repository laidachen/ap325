#include <bits/stdc++.h>
#define LL long long
using namespace std;

//整體想法是用分治演算法，逆數對可能會在左半邊，或是右半邊，或是橫跨中間到右邊

void dac(LL a[],int l,int r,LL &count) {
    if (l == r) {
        return;//用void沒做事的要加return
    }
    if (l+1==r && a[l]>a[r]) {
        count+=1;
        return;
    }
    int m = (r+l)/2;
    dac(a,l,m,count);
    dac(a,m+1,r,count);
    sort(a+m+1,a+r+1);//sort要排序區間的用法是sort(起點,終點後一位)，像這樣會排序[m+1,r]
    for (int i=l; i<=m; i++) {
        int where = m;
        for (int dis=r-m; dis>0; dis=dis/2) {//用二分搜找最大的逆數對
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
