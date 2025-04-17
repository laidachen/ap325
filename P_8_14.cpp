#include <bits/stdc++.h>
#define N 100000
using namespace std;

//設dp[n][0]為點n往下的最長一邊，dp[n][1]為第二長一邊，樹的直徑是以這點為最高點加上兩邊邊長的最大值
//dp[n][0] = max(dp[k][0])+1 k是n的孩子
//dp[n][1] = max(dp[k][0])+1 k不能是上面選到的k，還要注意是不是沒有第二條邊，沒有就是0

vector<int> out[N];
vector<int> in[N];
int dp[N][2] = {0};
int nowmax = 0;

int dpp(int n,int state) {
    if (dp[n][state]!=0) {
        return dp[n][state];
    } else {
        if (out[n].size()==0) {
            return dp[n][state] = 0;
        } else {
            int maxn = 0;
            int where = 0;
            for (int i=0; i<out[n].size(); i++) {
                dpp(out[n][i],1);//記得找的時候也求出這點的第二長邊是甚麼
                int dp0 = dpp(out[n][i],0);
            	if (dp0>maxn) {
            		where = i;
            		maxn = dp0;
				}
            }
            int maxn2 = -1;
            for (int i=0; i<out[n].size(); i++) {
                if (i!=where) {
					maxn2 = max(maxn2,dpp(out[n][i],0));
                }
            }
            if (maxn2!=-1) {
                nowmax = max(nowmax,maxn+1+maxn2+1);
            } else {
                nowmax = max(nowmax,maxn+1);
            }
            if (state==0) {
                return dp[n][0] = maxn+1;
            } else {
            	if (maxn2==-1) {
            		return dp[n][1] = 0;
				} else {
					return dp[n][1] = maxn2+1;
				}
            }
        }
    }
}


int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,a,b,where;
    cin>>n;
    for (int i=0; i<n-1; i++) {
        cin>>a>>b;
        out[a].push_back(b);
        in[b].push_back(a);
    }
    for (int i=0; i<n; i++) {
        if (in[i].size()==0) {
            where=i;
            break;
        }
    }
	dpp(where,0);
	dpp(where,1);
    cout<<nowmax;
    return 0;
}