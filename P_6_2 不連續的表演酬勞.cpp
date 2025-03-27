#include <bits/stdc++.h>
using namespace std;

//top down
//這一題的遞迴關係式是dp[i] = max(d[i]+dp[i-2],dp[i-1]) i>2
//考慮看看如果今天不做，就代表昨天要做，或是今天做，代表昨天不能做，是要加前天的最大獲益，兩個比大小就好
//bottom up的寫法是找出計算順序後用迴圈推出來
//top down的寫法是紀錄一個表格後用遞迴的寫法，然後找這表格有沒有算過，如果算過就回傳，不然就算一遍並更新上去

int d[100001] = {0};
int dp[100001] = {0};
int maxincome(int n) {
    if (dp[n]>0) {
        return dp[n];
    } else {
        dp[n] = max(maxincome(n-1),d[n]+maxincome(n-2));
        return dp[n];
    }
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,temp;
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>temp;
        d[i]= temp;
    }
    dp[1] = d[1];
    dp[2] = max(d[1],d[2]);
    cout<<maxincome(n);
    return 0;
}
