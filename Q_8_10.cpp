#include <bits/stdc++.h>
#define N 100000
using namespace std;
//設dp[n][0]為這點不設監聽器且他底下的樹都有被監聽到的監聽器最小數量，dp[n][1]為這點有設監聽器且他底下的樹都有被監聽到的監聽器最小數量
//則關係式為dp[n][0]=sigma(dp[k][1]) k是n的鄰居，因為這點不設所以他底下的點都要設置才能每個通話都被監聽到
//dp[n][0]=sigma(min(dp[k][0],dp[k][1])) ，因為這點設置了底下的孩子都可以被監聽到，所以底下要設或不設取最小的

vector<int> out[N];
int dp[N][2];
int dpp(int n,int state,int parent) {//避免走訪到自己的parent所以要記錄起來
    if (dp[n][state]!=0) {
        return dp[n][state];
    } else {
        if (n!=0&&out[n].size()==1) {
            if (state) {
                return 1;
            } else {
                return 0;
            }
        }
        if (state) {
            int num = 1;
            for (int i=0; i<out[n].size(); i++) {
                if (out[n][i]!=parent) {
                    num+=min(dpp(out[n][i],0,n),dpp(out[n][i],1,n));
                }
            }
            return dp[n][state] = num;
        } else {
            int num = 0;
            for (int i=0; i<out[n].size(); i++) {
                if (out[n][i]!=parent) {
                    num+=dpp(out[n][i],1,n);
                }
            }
            return dp[n][state] = num;
        }
    }
}


int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,t;
    cin>>n;
    for (int i=1; i<=n-1; i++) {
        cin>>t;
        out[t].push_back(i);
        out[i].push_back(t);
    }
    cout<<min(dpp(1,0,-1),dpp(1,1,-1));
    return 0;
}