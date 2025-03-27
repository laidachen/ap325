#include <bits/stdc++.h>
#define LL long long
using namespace std;

//模逆元是(a*b)%p=1的整數b
//透過講義提示的費馬小定理(若p為質數 (a^p-2 % p)就是乘法反元素

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    LL n,p,temp,b,r,a;
    vector<LL> num;
    cin>>n>>p;
    for (int i=0; i<n; i++) {
        cin>>temp;
        num.push_back(temp);
    }
    for (int i=0; i<n; i++) {
        b = p-2;
        r = 1;
        a = num[i]%p;
        while(b>0) {
            if (b%2==1) {
                r = (r*a)%p;
            }
            a = (a*a)%p;//(a*b) mod k = (a mod k*b mod k) mod k
            b = b>>1;
        }
        cout<<r;
        if (i!=n-1) {
            cout<<" ";
        }
    }
    return 0;
}