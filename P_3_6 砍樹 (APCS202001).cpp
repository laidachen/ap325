#include <bits/stdc++.h>
using namespace std;

//假如說砍完可以砍的樹之後，保留下來的樹要被砍的話，要等他右邊的樹被砍掉才有可能自己能被砍
//整體思路是由左到右砍樹，如果能砍的話就砍掉，之後判斷stack裡面的樹也能不能被砍，如果不能被砍就放在stack裡面

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    int num = 0;
    long long l,temp;
    long long tallest = 0;
    vector<long long> tree;
    vector<long long> treeh;
    stack<int> cut;
    cin>>n>>l;
    //增加邊界預防出錯
    tree.push_back(0);
    treeh.push_back(0);
    for (int i=0; i<n; i++) {
        cin>>temp;
        tree.push_back(temp);
    }
    for (int i=0; i<n; i++) {
        cin>>temp;
        treeh.push_back(temp);
    }
    //增加邊界預防出錯
    tree.push_back(l);
    treeh.push_back(0);
    cut.push(0);
    for (int i=1; i<=n; i++) {
        if ((tree[i]-treeh[i]>=tree[cut.top()])||(tree[i]+treeh[i]<=tree[i+1])) {//要往左倒的條件是，樹倒後的位置要小於沒被砍的樹的位置，要往右倒的條件是樹倒後的位置要小於下一棵樹在的位置
            num += 1;
            if (treeh[i]>tallest) {
                tallest = treeh[i];
            }
            while (true) {//因為可能可以一直砍下去，所以要用while
                if (cut.top()==0) {
                    break;
                }
                if ((tree[cut.top()]+treeh[cut.top()]<=tree[i+1])) {//stack裡面的樹都是往左邊跟往右邊都砍不了的樹，現在右邊的樹被砍了之後才有機會判斷可不可以往右邊倒
                    num += 1;
                    if (treeh[cut.top()]>tallest) {
                        tallest = treeh[cut.top()];
                    }
                    cut.pop();
                } else {
                    break;
                }
            }
        } else {
            cut.push(i);
        }
    }
    cout<<num<<endl;
    cout<<tallest<<endl;
    return 0;
}