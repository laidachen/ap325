#include <bits/stdc++.h>
using namespace std;
#define LL long long

//分治的思維是拆成兩邊，然後兩邊各自用遞迴解決問題後最後合併
//這題的解法是拆成左右兩區間，最大值可能在左邊或是右邊，或是中間，所以中間也要考慮

LL dac(vector<LL> &a,LL l,LL r) {//如果沒有傳參考每次呼叫一次函式都會複製一次vector，這就是導致TLE的問題，傳參考就是直接調用原本的a
    if (l+1==r) {//到最底要回傳值
        return max(a[l],a[r]);
    }
    if (l==r) {
        return a[l];
    }
    LL m = (r+l)/2;
    LL largest = max(dac(a,l,m),dac(a,m+1,r));//拆成左邊跟右邊並比大小

    LL total = 0;
    LL maxls = 0;
    LL maxrs = 0;
    for (LL i=m; i>=l; i--) {
        total+=a[i];
        if (total>maxls) {
            maxls = total;
        }
    }
    total = 0;
    for (LL i=m+1; i<=r; i++) {
        total+=a[i];
        if (total>maxrs) {
            maxrs = total;
        }
    }
    LL maxm = maxls+maxrs;
    return max(maxm,largest);//跟中間比較
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    LL n,temp;
    vector<LL> a;
    cin>>n;
    for (LL i=0; i<n; i++) {
        cin>>temp;
        a.push_back(temp);
    }
    LL vaule = dac(a,0,n-1);
    if (vaule<0) {
        cout<<0;
    } else {
        cout<<vaule;
    }
    return 0;
}
