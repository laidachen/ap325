#include <bits/stdc++.h>
#define LL long long
using namespace std;

//雙指針解法(陣列要排序過):先設定一個指針在原點,一個指針要在終點,目標是算出兩個值相加等於k,就先讓右指針移到小於或等於k-a[i]的位置,再判斷是否等於,
//接下來左指針往右移,a[i]值變大,k-a[i]變小,右指針可能就會大於k-a[i],所以就要判斷有沒有大於,如果大於就要讓右指針往左移,一值重複這動作

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    LL m,n,k,temp;
    int count,where;
    count = 0;
    vector<LL> a;
    vector<LL> b;
    cin>>m>>n>>k;
    for (int i=0; i<m; i++) {
        cin>>temp;
        a.push_back(temp);
    }
    for (int i=0; i<n; i++) {
        cin>>temp;
        b.push_back(temp);
    }
    sort(a.begin(),a.end());//先排序a跟b陣列
    sort(b.begin(),b.end());
    where = n-1;
    for (int i=0; i<m; i++) {//i是左指針
        while (where>0 && b[where]>k-a[i]) {//where是右指針
            where--;
        }
        if (b[where]+a[i]==k) {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}