#include <bits/stdc++.h>
using namespace std;

//解法是每次讓讀取到的顏色的計數器+1,判斷+1的時候如果為1就代表是新顏色，如果i==l就開始判斷減掉i-1那個位置的顏色會不會等於0，等於0代表顏色少一種

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,l,temp;
    int color = 0;
    int colorn = 0;
    cin>>n>>l;
    vector<int> a;
    int num[200001] = {0};//每個顏色的計數器，不會用到引索值0
    for (int i=0; i<n; i++) {
        cin>>temp;
        a.push_back(temp);
    }
    for (int i=0; i<n; i++) {
        if (num[a[i]]+1==1) {
            color++;
        }
        num[a[i]]+=1;
        if (i>=l) {//等於的時候減起來剛好等於0，ex: l==3 0 1 2 3，i等於3的時候減起來剛好是1的前面
            if (num[a[i-l]]-1==0) {
                color--;
            }
            num[a[i-l]]-=1;
        }
        if (color>colorn) {
            colorn=color;
        }
    }
    cout<<colorn;
    return 0;
}