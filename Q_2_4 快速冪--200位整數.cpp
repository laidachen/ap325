#include <bits/stdc++.h>
#define LL long long
using namespace std;

int extrapow(LL x,LL y,LL p) {
    LL r = 1;
    LL a = x;
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
    LL y,p,r;
    r = 0;
    string x;//因為可能會有200位數，所以要用字串處理
    cin>>x>>y>>p;
    r = ((int(x[0])-48)*10)%p;//根據講義裡給的提示，先做第一個數字乘以10取餘數，再用迴圈每加一項取一次餘數再乘以10取餘數，最後一項加起來取餘數就好
    for (int i=1; i<x.size(); i++) {
        if (i==x.size()-1) {
            r = (r+int(x[i])-48)%p;
        } else {
            r = (((r+int(x[i])-48)%p)*10)%p;
        }
    }
    cout<<extrapow(r,y,p);
    return 0;
}