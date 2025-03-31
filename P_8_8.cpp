#include <bits/stdc++.h>
#define N 100001
using namespace std;

//設dp[n][0]為不採計這節點，節點下面的最大獨立集，dp[n][0]為採計這節點，節點下面的最大獨立集
//關係式是dp[n][0] = sigma(max(dp[k][1],dp[k][0])) k是n的out neighbor，因為我這個點沒採計，所以有跟沒有都是可以的，所以要比大小求最大值
//dp[n][1] = sigma(dp[k][0])+1 k是n的out neighbor，因為這點有採計，所以只能用沒採計的
//最後再dp[0][0]跟dp[0][1]比大小就好了

vector<int> out[N];
int dp[N][2];
int dpp(int n,int get) {
    if (dp[n][get]!=0) {
        return dp[n][get];
    } else {
        if (out[n].empty()) {
            if (get) {
                return dp[n][1] = 1;
            } else {
                return dp[n][0] = 0;
            }
        }
        if (get) {
            int total = 1;
            for (int i=0; i<out[n].size(); i++) {
                total+=dpp(out[n][i],0);
            }
            dp[n][1] = total;
            return dp[n][1];
        } else {
            int total = 0;
            for (int i=0; i<out[n].size(); i++) {
                total+=max(dpp(out[n][i],0),dpp(out[n][i],1));
            }
            dp[n][0] = total;
            return dp[n][0];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,temp;
    cin>>n;
    for (int i=1; i<=n-1; i++) {
        cin>>temp;
        out[temp].push_back(i);
    }
    for (int i=0; i<n; i++) {
        if (out[i].size()==0) {
        }
    }
    cout<<max(dpp(0,1),dpp(0,0));
    return 0;
}