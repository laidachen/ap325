#include <bits/stdc++.h>
using namespace std;

//x座標經過排序後，x會遞增，所以可以判斷目前這個點的y座標是否大於或等於之前的控制點的y座標，有的話就可以刪掉之前的點的y座標，然後記得要加自己進去
//類似之前那個找最近的高人

struct xy {
    long long x,y;
};
bool compare(struct xy a,struct xy b) {
    if (a.x==b.x) {
        return a.y<b.y;//x相同但y小的要擺前面
    }
    return a.x<b.x;
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    long long temp;
    cin>>n;
    struct xy dot[n];
    stack<long long> max;
    for (int i=0; i<n; i++) {
        cin>>temp;
        dot[i].x=temp;
    }
    for (int i=0; i<n; i++) {
        cin>>temp;
        dot[i].y=temp;
    }
    sort(dot,dot+n,compare);
    for (int i=0; i<n; i++) {
        while(!max.empty()&&dot[i].y>=max.top()) {
            max.pop();
        }
        max.push(dot[i].y);
    }
    cout<<max.size();
    return 0;
}
