#include <bits/stdc++.h>
using namespace std;

//這題設dp[i][j]為第i天前，不出過j次買賣的最大獲利，接下來有兩個情況
//賣出p[i]，因為不知道p[i]跟前面哪天賣出會有最大獲利，所以他往前都要試過一遍dp[i][j] = max(p[i]-p[t]+dp[t-1][j-1]) t<i
//不賣出，就是dp[i][j] = dp[i-1][j]
//兩個取最大就好了
//如果要全試t<i這個範圍，複雜度就會是O(knn)，所以我維護一個變數，每次都會更新一次dp[d-1][b-1]-p[d]，看哪一個值是最大的就更新上去，之後每次算新的只要算p[i]+那個變數，就會等於p[i]-p[d]+dp[d-1][b-1]-p[d]

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;

    cin>>n>>k;
    vector<int> p(n+1,0);
    vector<vector<int>> dp(n+1,vector<int> (k+1,0));
    for (int i=1; i<=n; i++) {
        cin>>p[i];
    }
    for (int b=1; b<=k; b++) {
        int dm = dp[0][b-1]-p[1];
        for (int d=1; d<=n; d++) {
            dp[d][b] = max(p[d]+dm,dp[d-1][b]);
            dm = max(dm,dp[d-1][b-1]-p[d]);
        }
    }
    cout<<dp[n][k];
    return 0;
}

