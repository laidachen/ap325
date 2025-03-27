#include <bits/stdc++.h>
using namespace std;

//設dp[i]為前i個線段的最大經驗值，排序右端後關係式是dp[i]=max(dp[i-1],dp[j]+line[i].e) j<i line[j].t<line[i].s no maximum
//因為要一個一個回去找太慢了，又因為已經排序了右端，所以可以直接用二分搜找線段

struct c {
    int s,t,e;
};
bool compare(struct c a,struct c b) {
    return a.t<b.t;
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,temp,temp2,temp3;
    int where;
    int maxtotal = 0;
    cin>>n;
    struct c line[n];
    vector<int> dp(n,0);
    for (int i=0; i<n; i++) {
        cin>>temp>>temp2>>temp3;
        line[i].s = temp;
        line[i].t = temp2;
        line[i].e = temp3;
    }
    sort(line,line+n,compare);
    dp[0] = line[0].e;
    for (int i=1; i<n; i++) {
        where = i;
        for (int dis=i; dis>0; dis=dis/2) {
            while (where-dis>=0&&line[i].s<=line[where-dis].t) {//找的是右端，不用考慮左端
                where-=dis;
            }
        }
        if (where-1<0) {
            maxtotal = line[i].e;
        } else {
            maxtotal = line[i].e+dp[where-1];
        }
        dp[i] = max(maxtotal,dp[i-1]);
    }
    cout<<dp[n-1];
    return 0;
}
