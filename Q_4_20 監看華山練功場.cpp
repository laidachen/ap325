#include <bits/stdc++.h>
using namespace std;

//主要想法是用貪心演算法，先排序然後存一個右端點(x)，然後跑每個左端點都小於等於存的右端點的線段後，取線段的右端減目前存的右端點產生最大值的那條線，之後更新線段數跟右端點的值，直到右端點大於等於y。


struct c {
    long long s,t;
};
bool compare(struct c a,struct c b) {
    return a.s<b.s;
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    int ok = 1;
    long long now = 0;
    long long y = 0;
    long long total = 0;
    long long lmax = 0;
    long long l = 0;
    long long maxs = 0;
    long long maxt = 0;
    long long temp,temp2;
    cin>>n;
    cin>>now>>y;
    struct c persons[n];
    for (int i=0; i<n; i++) {
        cin>>temp>>temp2;
        persons[i].s = temp;
        persons[i].t = temp2;
    }
    sort(persons,persons+n,compare);
    for (int i=0; i<n; i++) {
        if (now>=y) {
            lmax = 0;//迴圈可能會跑新的線段
            break;
        }
        if (persons[i].s>now) {//代表全部小於等於右端點的線段都跑完了，要更新
            now = maxt;
            total++;
            lmax = 0;
            if (persons[i].s>now) {//還是大於就代表之後線段也是大於，故無解
                ok = 0;
                break;
            }
        }
        if (persons[i].t<=now) {//如果右端點小於等於存的右端點，代表這條線沒用
            continue;
        }
        l = persons[i].t-now;
        if (l>lmax) {
            lmax = l;
            maxs = persons[i].s;
            maxt = persons[i].t;
        }
    }
    if (lmax!=0) {//預防跑完後的值還沒更新
        total++;
        now = maxt;
    }
    if (now<y) {//預防跑完後的值還是沒大於等於y
        ok = 0;
    }
    if (ok) {
        cout<<total;
    } else {
        cout<<"-1";
    }
    return 0;
}
