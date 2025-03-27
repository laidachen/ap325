#include <bits/stdc++.h>
using namespace std;

//這題解法是最佳解的t/w一定會小於下一個w/t的值，然後我這題用struct存兩變數,然後相除排序出最小值,因為整數跟整數相除只會是整數,所以用浮點數來解,然後double的精度比較夠
//這題改交叉相乘會比較穩t/w<t2/w2-->t*w2<t2*w

struct tw {
    double t,w;
};
bool compare(struct tw a,struct tw b) {
    return (a.t/a.w)<(b.t/b.w);
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
        a[i].t = temp;
    }
    for (int i=0; i<n; i++) {
        cin>>temp;
        a[i].w = temp;
    }
    sort(a,a+n,compare);
    for (int i=0; i<n; i++) {
        total+=a[i].t;
        total2+=total*a[i].w;
    }
    cout<<total2;
    return 0;
}
