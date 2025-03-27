#include <bits/stdc++.h>
#define LL long long
using namespace std;

//整體思路是先往右找到有全部顏色的區間，接下來每往右一步就讓左指針往右減少寬度

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    set<LL> s;
    map<LL,int> m;
    vector<LL> a;
    int num[200000] = {0};
    int color = 0;
    int gcolor = 0;
    int left = 0;
    int n;
    LL temp;
    cin>>n;
    int length = n;
    //離散化，因為顏色會有10^9種
    for (int i=0; i<n; i++) {
        cin>>temp;
        a.push_back(temp);
        s.insert(temp);
    }
    int i=0;
    for (auto it=s.begin(); it!=s.end(); it++) {
        m[*it] = i;
        i++;
    }
    gcolor = i;
    for (int r=0; r<n; r++) {
        if (num[m[a[r]]]+1==1) {
            color++;
        }
        num[m[a[r]]]+=1;
        while(color>=gcolor) {
            if (num[m[a[left]]]-1==0) {
                color--;
            }
            num[m[a[left]]]-=1;
            if (color<gcolor) {//代表不能少掉這格
                num[m[a[left]]]+=1;
                color++;
                break;
            } else {
                left++;//可以少掉這個
            }
        }
        if (r-left+1<length&&color>=gcolor) {//目前彩帶有的顏色數要大於或等於目標顏色數，才能算進去長度裡面
            length = r-left+1;
        }
    }
    cout<<length;
    return 0;
}
