#include <bits/stdc++.h>
using namespace std;

//解法是希望越往上的取用次數越多，越往下的重量越重，代表w/f越往上值越小，經過了講義教的證明方法，發現這是對的

struct tw {
    double w,f;
};
bool compare(struct tw a,struct tw b) {
    return (a.w/a.f)<(b.w/b.f);
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    double temp;
    long long total = 0;
    long long total2 = 0;
    cin>>n;
    struct tw a[n];
    for (int i=0; i<n; i++) {
        cin>>temp;
        a[i].w = temp;
    }
    for (int i=0; i<n; i++) {
        cin>>temp;
        a[i].f = temp;
    }
    sort(a,a+n,compare);
    total+=a[0].w;
    for (int i=1; i<n; i++) {
        total2+=total*a[i].f;
        total+=a[i].w;
    }
    cout<<total2;
    return 0;
}
