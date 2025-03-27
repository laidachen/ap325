#include <bits/stdc++.h>
using namespace std;

//�]dp[i]���ei�ӽu�q���̤j�g��ȡA�Ƨǥk�ݫ����Y���Odp[i]=max(dp[i-1],dp[j]+line[i].e) j<i line[j].t<line[i].s no maximum
//�]���n�@�Ӥ@�Ӧ^�h��ӺC�F�A�S�]���w�g�ƧǤF�k�ݡA�ҥH�i�H�����ΤG���j��u�q

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
            while (where-dis>=0&&line[i].s<=line[where-dis].t) {//�䪺�O�k�ݡA���ΦҼ{����
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
