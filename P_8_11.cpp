#include <bits/stdc++.h>
#define N 100001
using namespace std;
//設dp[n][1]為這點有設且含他下面的樹的最大歡樂指數
//設dp[n][0]為這點沒設且含他下面的樹的最大歡樂指數
//dp[n][1] = sigma(dp[k][0])+r[n]
//dp[n][0] = sigma(max(dp[k][1],dp[k][0])) ，因為這點不選下面的可以選或不選，取最大

vector<int> out[N];
int r[N] = {0};
int dp[N][2];

int dpp(int n,int get,int parent) {
    if (dp[n][get]!=0) {
        return dp[n][get];
    } else {
        if (n!=1&&out[n].size()==1) {//可能1只有一個鄰居，這樣不能繼續往下判斷
            if (get) {
                return dp[n][1] = r[n];
            } else {
                return dp[n][0] = 0;
            }
        }
        if (get) {
            int total = 0;
            for (int i=0; i<out[n].size(); i++) {
                if (out[n][i]!=parent) {
                    total+=dpp(out[n][i],0,n);
                }
            }
            dp[n][1] = total+r[n];
            return dp[n][1];
        } else {
            int total = 0;
            for (int i=0; i<out[n].size(); i++) {
                if (out[n][i]!=parent) {
                    total+=max(dpp(out[n][i],0,n),dpp(out[n][i],1,n));
                }
            }
            dp[n][0] = total;
            return dp[n][0];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,temp;
    cin>>n>>r[1];
    for (int i=2; i<=n; i++) {
        cin>>temp>>r[i];
        out[temp].push_back(i);
        out[i].push_back(temp);
    }
    cout<<max(dpp(1,1,-1),dpp(1,0,-1));
    return 0;
}