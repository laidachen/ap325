#include <bits/stdc++.h>
#define LL long long
using namespace std;

//這題要先建立一個遞迴式，設dp[i][j]為長度為j且為i開頭的階梯數字數，接下來他的遞迴式是，dp[i][j] += dp[k][j-1] for all i<=k<=9
/*接下來要拆解題目問的數字，假如說n=2789，算的步驟分別為，
i=0且j=4的階梯數字數，i=1且j=4的階梯數字數，接下來因為2開頭的4位數不是每個都有可能
，所以要分開來算，之後是2"2"開頭的三位數的階梯數字數，一直算到2"6"開頭的三位數的階梯數字數，之後再分開算，以此類推直到算到最後，因為8"9"下一位沒數字了，所以最後長度為一的時候要算完不能分開算*/
//不會漏算，因為有0開頭的數，可以算到裡面的

LL dpp (int i,int j,vector<vector<LL>> &dp) {
    if (dp[i][j]!=-1) {
        return dp[i][j];
    } else {
        if (j==1) {
            return 1;
        }
        if (i==9) {
            return 1;
        }
        LL total2 = 0;
        for (int i2=i; i2<=9; i2++) {
            total2+=dpp(i2,j-1,dp);
        }
        return dp[i][j] = total2;
    }
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    LL total = 0;
    string n;
    cin>>n;
    vector<vector<LL>> dp(10,vector<LL> (19,-1));
    dp[0][1] = 0;
    int len = n.size();
    int last = 0;
    for (int i=0; i<n.size(); i++) {
        if (int(n[i])-48<last) {//這一位數小於上一位數的話就可以不用算了
            break;
        }
        if (len==1) {
            for (int i2=last; i2<=int(n[i])-48; i2++) {
                total+=dpp(i2,len,dp);
            }
            break;
        }
        for (int i2=last; i2<int(n[i])-48; i2++) {
            total+=dpp(i2,len,dp);
        }
        last = int(n[i])-48;
        len-=1;
    }
    cout<<total;
    return 0;
}
