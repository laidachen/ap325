#include <bits/stdc++.h>
#define N 100001
using namespace std;
//參考P_8_13但沒加權種
vector<int> out[N];
int dp[N][3];
int dpp(int n,int state,int parent) {
    int total = 0;
    int a = INT_MAX;
    if (dp[n][state]!=0) {
        return dp[n][state];
    } else {
        if (n!=1&&out[n].size()==0&&state==0) {
            return dp[n][0] = 1;
        }
        if (n!=1&&out[n].size()==0&&state==1) {
            return dp[n][1] = INT_MAX;
        }
        if (n!=1&&out[n].size()==0&&state==2) {
            return dp[n][2] = 0;
        }
        if (state==0) {
            for (int i=0; i<out[n].size(); i++) {
                if (out[n][i]!=parent) {
                    total+=min({dpp(out[n][i],0,n),dpp(out[n][i],1,n),dpp(out[n][i],2,n)});
                }
            }
            return dp[n][0] = total+1;
        } else if (state==1) {
            for (int i=0; i<out[n].size(); i++) {
                if (out[n][i]!=parent) {
                    total+=min(dpp(out[n][i],0,n),dpp(out[n][i],1,n));
                    a = min(a,dpp(out[n][i],0,n)-dpp(out[n][i],1,n));
                }
            }
            a = max(a,0);
            return dp[n][1] = total+a;
        } else {
            for (int i=0; i<out[n].size(); i++) {
                if (out[n][i]!=parent) {
                    total+=min(dpp(out[n][i],0,n),dpp(out[n][i],1,n));
                }
            }
            return dp[n][2] = total;
        }
    }
}


int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,u,v;
    cin>>n;
    for (int i=0; i<n-1; i++) {
        cin>>u>>v;
        out[u].push_back(v);
        out[v].push_back(u);
    }
    cout<<min(dpp(1,0,0),dpp(1,1,0));
    return 0;
}