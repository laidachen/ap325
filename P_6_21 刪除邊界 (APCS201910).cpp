#include <bits/stdc++.h>
using namespace std;

int dp[26][26][26][26] = {{{{0}}}};

//設dp[x1][x2][y1][y2]為刪除左上角為x1,y1右下角為x2,y2矩陣的最小成本，那接下來只要用遞迴算出刪除上下左右四邊分別的成本最後比看誰最小就好了
//top down的寫法

int dpp(int x1,int x2,int y1,int y2,vector<vector<int>> &a) {
    if (dp[x1][x2][y1][y2]!=0) {
        return dp[x1][x2][y1][y2];
    } else {
        if (y1==y2) {
            return 0;
        }
        if (x1==x2) {
            return 0;
        }
        int z = 0;
        int o = 0;
        int s = 0;
        int s2 = 0;
        int s3 = 0;
        int s4 = 0;
        int where = 0;
        //up side
        for (int i=x1; i<=x2; i++) {
            if (a[y1][i]==1) {
                o+=1;
            } else {
                z+=1;
            }
        }
        s = min(z,o);
        //bottom side
        z = 0;
        o = 0;
        for (int i=x1; i<=x2; i++) {
            if (a[y2][i]==1) {
                o+=1;
            } else {
                z+=1;
            }
        }
        s2 = min(z,o);
        //left side
        z = 0;
        o = 0;
        for (int i=y1; i<=y2; i++) {
            if (a[i][x1]==1) {
                o+=1;
            } else {
                z+=1;
            }
        }
        s3 = min(z,o);
        //right side
        z = 0;
        o = 0;
        for (int i=y1; i<=y2; i++) {
            if (a[i][x2]==1) {
                o+=1;
            } else {
                z+=1;
            }
        }
        s4 = min(z,o);
        return dp[x1][x2][y1][y2] = min({s+dpp(x1,x2,y1+1,y2,a),s2+dpp(x1,x2,y1,y2-1,a),s3+dpp(x1+1,x2,y1,y2,a),s4+dpp(x1,x2-1,y1,y2,a)});
    }
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int m,n;
    cin>>m>>n;
    vector<vector<int>> a(26,vector<int> (26,0));
    for (int i=1; i<=m; i++) {
        for (int i2=1; i2<=n; i2++) {
            cin>>a[i][i2];
        }
    }
    cout<<dpp(1,n,1,m,a);
    return 0;
}
