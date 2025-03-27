#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    set<LL> s;
    map<LL,int> ma;
    vector<LL> a;
    int num[200000] = {0};
    int n,m;
    int num2=0;
    int r = 0;
    LL temp;
    cin>>m>>n;
    //弄離散化
    for (int i=0; i<n; i++) {
        cin>>temp;
        a.push_back(temp);
        s.insert(temp);
    }
    int i = 0;
    for (auto it=s.begin(); it!=s.end(); it++) {
        ma[*it] = i;
        i++;
    }
    //跟Q_3_11概念差不多，先找到最大的相異區間再判斷長度是不是m
    num[ma[a[0]]]=1;
    for (int l=0; l<n; l++) {
        if (l>0) {
            num[ma[a[l-1]]]=0;
        }
        while(r+1<n&&num[ma[a[r+1]]]==0) {
            num[ma[a[r+1]]]=1;
            r++;
        }
        if(r-l+1==m) {
            num2++;
        }
    }
    cout<<num2;
    return 0;
}
