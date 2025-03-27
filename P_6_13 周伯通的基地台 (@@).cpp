#include <bits/stdc++.h>
using namespace std;

//設dp[i]為前i個區域都有覆蓋到且最後一個基地台設在i的最小成本
//關係式dp[i]=c[i]+dp[i-2k-1~i-1]的最小值
//因為要找到最小值，然後不可能找不在i-2k-1~i-1這區間的，不然就會沒全部覆蓋到
//因為藥用迴圈跑區間內最小值太慢了，所以用一個deque維護區間內的最小值

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;
    int line = 0;
    cin>>n>>k;
    vector<int> c(n+1,0);
    vector<int> dp(n+1,0);
    deque<int> m;
    for (int i=1; i<=n; i++) {
        cin>>c[i];
    }
    //初始化
    for (int i=1; i<=k+1; i++) {
        dp[i] = c[i];
        while(!m.empty()&&dp[m.back()]>=dp[i]) {
            m.pop_back();
        }
        m.push_back(i);
    }
    for (int i=k+2; i<=n; i++) {
        line = i-k-k-1;
        while(!m.empty()&&m.front()<line) {//刪除小於i-2k-1的值
            m.pop_front();
        }
        if (!m.empty()) {
            dp[i] = c[i]+dp[m.front()];
        } else {
            dp[i] = c[i];
        }
        while(!m.empty()&&dp[m.back()]>=dp[i]) {//如果dp[i]的值小於前面的值，代表前面就不會是最小值
            m.pop_back();
        }
        m.push_back(i);
    }
    line = n-k;//答案不會只出現在dp[n]是會出現在n-k~n這區間裡面，因為都能蓋到全部
    while(!m.empty()&&m.front()<line) {
        m.pop_front();
    }
    cout<<dp[m.front()];
    return 0;
}
