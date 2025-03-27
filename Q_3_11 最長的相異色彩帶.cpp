#include <bits/stdc++.h>
using namespace std;

//整體思路是，假如每個頭都要往前跑找到重複的顏色的話，最壞的複雜度就是o(n^2)，那如果前一個頭已經跑到了他重複的地方，
//代表在那重複地方之前這區間都是不重複的，所以下一個頭可以用前一個頭跑過的結果再繼續往前偵測有沒有重複，整體複雜度是O(n)。

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,temp;
    int right = 0;
    int color = 1;
    int colorn = 0;
    vector<int> a;
    int num[200001] = {0};//記得要初始化
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>temp;
        a.push_back(temp);
    }
    num[a[0]] = 1;//一開始有一個顏色
    for (int i=0; i<n; i++) {
        if (i>0) {//把前一個顏色刪掉
            num[a[i-1]]=0;
            color--;
        }
        if (right<i) {//判斷右指針小於左指針要重新初始化
            right=i;
            color=1;
            num[a[i]] = 1;
        }
        while(right+1<n && num[a[right+1]]+1==1) {
            num[a[right+1]]+=1;
            right++;
            color++;
        }
        if (color>colorn) {
            colorn=color;
        }
    }
    cout<<colorn;
    return 0;
}