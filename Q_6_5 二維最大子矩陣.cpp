#include <bits/stdc++.h>
using namespace std;

//主要用之前p-4-13的卡丹算法，之後設一個底跟一個最上限，然後用一個一維陣列表示從高加到底的值，之後用卡丹算法，高更新時，底就要一直往上算一遍到跟高一樣，這樣才能算到全部的和

void add(vector<int> &total,int a[201][201],int top,int m,int n) {//vector才能傳參考
    for (int i=1; i<=n; i++) {
        for (int i2=m; i2>=top; i2--) {
            total[i]+=a[i2][i];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int m,n,temp;
    int a[201][201] = {0};
    vector<int> total(201,0);
    int maxn = -1*4*pow(10,8);
    cin>>m>>n;
    for (int i=1; i<=m; i++) {
        for (int i2=1; i2<=n; i2++) {
            cin>>temp;
            a[i][i2] = temp;
        }
    }
    for (int top=1; top<=m; top++) {//高
        add(total,a,top,m,n);//從高加到底的函式
        for (int down=m; down>=top; down--) {//底
            int now = total[1];
            maxn = max(now,maxn);
            for (int i=2; i<=n; i++) {//卡丹算法
                if (total[i]+now>=total[i]) {
                    now+=total[i];
                } else {
                    now = total[i];
                }
                maxn = max(now,maxn);
            }
            for (int i=1; i<=n; i++) {
                total[i]-=a[down][i];
            }
        }
    }
    cout<<maxn;
    return 0;
}
