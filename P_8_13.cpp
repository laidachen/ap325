#include <bits/stdc++.h>
#define N 100001
using namespace std;
//設dp[n][0]為建立服務中心在這且加上下面的最小成本
//設dp[n][1]為不建立服務中心在這且加上下面的最小成本，且有被照顧到
//設dp[n][2]為不建立服務中心在這且加上下面的最小成本，且不一定有被照顧到，要被上面的點管
//dp[n][0] = min({dp[k][0],dp[k][1],dp[k][2]}) k是n的孩子，因為這點有設，所以三種狀況都能照顧到下面的點
//dp[n][1] = min(dp[k][0],dp[k][1])+max(0,min(dp[k][0]-dp[k][1])) ，max(0,min(dp[k][0]-dp[k][1]))是用來看看有沒有至少選一個設服務中心在那點的點
//如果dp[k][0]-dp[k][1]的最小值是正的，就全部沒人選dp[k][0]，所以要補一個差值最小的換上去，如果dp[k][0]-dp[k][1]是負的，就代表有選到dp[k][0](因為dp[k][0]<dp[k][1])
//dp[n][2] = min(dp[k][0],dp[k][1])

vector<int> out[N];
int w[N] = {0};
int dp[N][3];
int dpp(int n,int state,int parent) {
    int total = 0;
    int a = INT_MAX;
    if (dp[n][state]!=0) {
        return dp[n][state];
    } else {
        if (n!=1&&out[n].size()==0&&state==0) {
            return dp[n][0] = w[n];
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
            return dp[n][0] = total+w[n];
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
    for (int i=1; i<=n; i++) {
        cin>>w[i];
    }
    for (int i=0; i<n-1; i++) {
        cin>>u>>v;
        out[u].push_back(v);
        out[v].push_back(u);
    }
    cout<<min(dpp(1,0,0),dpp(1,1,0));
    return 0;
}