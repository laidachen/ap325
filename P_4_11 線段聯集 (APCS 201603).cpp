#include <bits/stdc++.h>
using namespace std;

/*想像有一條線掃過去，如果一個新掃到的線段的左端大於目前線段的右端，
代表這條線段跟之後的線段(有排序過)不會跟先前的線段有聯集，
所以可以算新的線段，至於左端沒大於目前右端，代表是可以取交集的線段
，在看看他的右端有沒有大於目前的右端就好了，有的話就換上去*/

struct line {
    long long left,right;
};
bool compare(struct line a,struct line b) {
    return a.left<b.left;
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    long long temp,temp2;
    long long ln = 0;
    long long rn = 0;
    long long total = 0;
    cin>>n;
    struct line l[n];
    for (int i=0; i<n; i++) {
        cin>>temp>>temp2;
        l[i].left = temp;
        l[i].right = temp2;
    }
    sort(l,l+n,compare);
    for (int i=0; i<n; i++) {
        if (l[i].left>rn) {
            total+=rn-ln;
            ln = l[i].left;
            rn = l[i].right;
            continue;
        }
        if (l[i].right>rn) {
            rn = l[i].right;
        }
    }
    total+=rn-ln;
    cout<<total;
    return 0;
}
