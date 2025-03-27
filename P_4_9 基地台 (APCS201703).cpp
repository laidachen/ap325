#include <bits/stdc++.h>
using namespace std;

//解法是想像每條半徑都是一條線，看線蓋到每一個點的數量是否<=k，直徑用二分搜來找，之後還要有一個判斷是否足夠的函數，只要用迴圈判斷就好了

int ok(int m,vector<long long>line,int k) {
    int total = 1;
    long long where = line[0];
    for (int i=0; i<line.size(); i++) {
        if (line[i]<=where+m) {
            continue;
        } else {
            total++;//沒覆蓋到就要再花一個線段，從那邊開始
            where=line[i];
        }
    }
    if (total<=k) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;
    long long temp;
    long long r = 1000000000;
    long long l = 0;
    long long ans = 0;
    vector<long long> line;
    cin>>n>>k;
    for (int i=0; i<n; i++) {
        cin>>temp;
        line.push_back(temp);
    }
    sort(line.begin(),line.end());
    while(l<=r) {
        long long m = (r+l)/2;
        if (ok(m,line,k)) {
            ans = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
