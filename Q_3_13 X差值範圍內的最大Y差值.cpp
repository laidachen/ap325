#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    LL l,temp;
    LL maximum = 0;
    LL maxy = 0;
    LL miny = 0;
    LL total = 0;
    int n;
    int right = 0;
    vector<vector<LL>> a;
    vector<LL> add = {0,0};
    cin>>n>>l;
    for (int i=0; i<n; i++) {
        cin>>temp;
        add[0] = temp;
        a.push_back(add);
    }
    for (int i=0; i<n; i++) {
        cin>>temp;
        a[i][1] = temp;
    }
    sort(a.begin(),a.end());
    for (int left=0; left<n; left++) {
        if (right<left) {
            right = left;
        }
        //維護區間
        if (left<miny) {
            total = abs(a[miny][1]-a[left][1]);
            if (total>maximum) {
                maximum = total;
            }
        } else {//更新區間內最小值
            miny=left;
            for (int i=left; i<=right; i++) {
                if (a[i][1]<=a[miny][1]) {
                    miny = i;
                }
            }
            total = abs(a[miny][1]-a[left][1]);
            if (total>maximum) {
                maximum = total;
            }
        }
        if (left<maxy) {
            total = abs(a[maxy][1]-a[left][1]);
            if (total>maximum) {
                maximum = total;
            }
        } else {//更新區間內最大值
            maxy=left;
            for (int i=left; i<=right; i++) {
                if (a[i][1]>=a[maxy][1]) {
                    maxy = i;
                }
            }
            total = abs(a[maxy][1]-a[left][1]);
            if (total>maximum) {
                maximum = total;
            }
        }

        while(right+1<n&&abs(a[right+1][0]-a[left][0])<=l) {
            right++;
            total = abs(a[right][1]-a[left][1]);
            if (a[right][1]>=a[maxy][1]) {
                maxy = right;
            }
            if (a[right][1]<=a[miny][1]) {
                miny = right;
            }
            if (total>maximum) {
                maximum = total;
            }
        }
    }
    cout<<maximum;
    return 0;
}
