#include <bits/stdc++.h>
using namespace std;

//整體思路是對答案作二分搜，然後每次都看喝水的次數有沒有小於最多喝水次數，如果有代表這值大於目標的值，所以右邊要-1

int ok(long long mid,vector<int> guan,int m) {
    int total = 0;
    int f = mid;
    for (int i=0; i<guan.size(); i++) {
        if (f<guan[i]) {
            total++;
            f = mid;
            if (f<guan[i]) {//預防喝水還是沒過
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
