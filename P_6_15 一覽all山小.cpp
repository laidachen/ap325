#include <bits/stdc++.h>
using namespace std;

//硂肈砞dp[i]i翴琌程┕玡LIS计闽玒Α琌dp[i] = max(dp[j])+1 j<i a[j]<a[i]
//安–Ω常璶禲Ω玡狡馒穦琌O(n^2)弄–j<ia[j]>=a[i]dp[j]<=dp[i]碞êj⊿Τノ
//┮承皚ノㄓL程ぇ癸–常暗だ穓琌患糤计禫ぃ程穦禫т碞矪瞶氮皚程よ

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    vector<int> l(1,0);
    for (int i=1; i<=n; i++) {
        cin>>a[i];
    }
    for (int i=1; i<=n; i++) {
        int where = 0;
        for (int dis=l.size(); dis>0; dis=dis/2) {
            while (where+dis<l.size()&&a[i]>l[dis+where]) {
                where+=dis;
            }
        }
        if (where+1==l.size()) {
            l.push_back(a[i]);
        } else {
            if (a[i]<l[where+1]) {
                l[where+1] = a[i];
            }
        }
    }
    cout<<l.size()-1;
    return 0;
}
