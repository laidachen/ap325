#include <bits/stdc++.h>
#define N 100001
using namespace std;

//設dp[n][1]為其中一點設在這且包含他下面的路徑的最大利益
//設dp[n][0]為這點含以下的路徑的最大利益
//則關係式
//dp[n][1] = sigma(max(dp[k][1],0) k是n的child，因為這點要設置，代表也要跟其他點相連，又因為是最大利益，所以如果小於0就不需要他
//dp[n][0] = max(dp[n][1],dp[k][0]) k是n的child，因為是含這點以下路徑的最大利益，所以要比大小，其中選dp[k][0]而不是dp[k][1]的原因是，假如dp[k][1]是這點往下路徑的最大值，那dp[k][0]會等於dp[k][1]


vector<int> w(N,0);
vector<int> out[N];
int dp[N][2];
int dpp(int n,int state,int parent) {
    if (dp[n][state]!=0) {
        return dp[n][state];
    } else {
        if (n!=1&&out[n].size()==1) {
            dp[n][0] = w[n];
            return dp[n][1] = w[n];
        } else {
            if (state) {
                int total = w[n];
                for (int i=0; i<out[n].size(); i++) {
                    if (out[n][i]!=parent) {
                        if (dpp(out[n][i],1,n)>=0) {
                            total+=dpp(out[n][i],1,n);
                        }
                    }
                }
                return dp[n][1] = total;
            } else {
                int total = 0;
                for (int i=0; i<out[n].size(); i++) {
                    if (out[n][i]!=parent) {
                        total=max({dpp(out[n][i],0,n),0,total});
                    }
                }
                return dp[n][0] = max(dpp(n,1,parent),total);
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,u,v;
    int where = 0;
    int maxn = INT_MIN;
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>w[i];
    }
    for (int i=0; i<n-1; i++) {
        cin>>u>>v;
        out[u].push_back(v);
        out[v].push_back(u);
    }
    dpp(1,0,0);
    cout<<dp[1][0];
    return 0;
}