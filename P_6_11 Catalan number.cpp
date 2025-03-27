#include <bits/stdc++.h>
#define LL long long
#define P 1000000009
using namespace std;

LL c(int n,vector<LL> &a) {
    if (n==0) {
        return 1;
    }
    if (a[n]!=-1) {
        return a[n];
    } else {
        LL total = 0;
        for (int i=0; i<n; i++) {
            total = (total+(c(i,a)*c(n-1-i,a))%P)%P;//(a*b) mod k = (a mod k*b mod k) mod k / (a+b) mod k = (a mod k+b mod k) mod k
        }
        a[n] = total;
        return a[n];
    }
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    vector<LL> a(100,-1);
    a[0] = 1;
    cin>>n;
    cout<<c(n,a);
    return 0;
}
