#include <bits/stdc++.h>
#define LL long long
using namespace std;

int extrapow(LL x,LL y,LL p) {
    LL r = 1;
    LL a = x%p;
    while (y!=0) {
        if (y%2==1) {
            r = (r*a)%p;
        }
        a = (a*a)%p;//a*b mod k = (a mod k * b mod k) mod k
        y = y>>1;
    }
    return r;
}

int main(void) {
    LL x,y,p;
    cin>>x>>y>>p;
    cout<<extrapow(x,y,p);
    return 0;
}