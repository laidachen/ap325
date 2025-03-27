#include <bits/stdc++.h>
using namespace std;

//設dp[i][j]為s1第i個字元往前與s2第j個字元往前的LCS數
//會有兩種狀況
//s1[i] == s2[j]，這時候要求出dp[i-1][j-2]再+1，因為他們字元一樣
//s1[i] != s2[j]，這時候代表至少有一個字元對算LCS是沒用的，所以求出dp[i-1][i2]，dp[i][i2-1]，dp[i-1][i2-1]比大小就好了
//初始條件是dp[i][0]跟dp[0][j]，因為有一個是空字串，所以LCS是0

int main(void) {
    string s1,s2;
    int dp[501][501] = {0};
    cin>>s1;
    cin>>s2;
    for (int i=1; i<=s1.size(); i++) {
        for (int i2=1; i2<=s2.size(); i2++) {
            if (s1[i-1]==s2[i2-1]) {
                dp[i][i2] = dp[i-1][i2-1]+1;
            } else {
                dp[i][i2] = max(max(dp[i-1][i2],dp[i][i2-1]),dp[i-1][i2-1]);
            }
        }
    }
    cout<<dp[s1.size()][s2.size()];
    return 0;
}
