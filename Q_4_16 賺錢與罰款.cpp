#include <bits/stdc++.h>
using namespace std;

//如果要每個訂單都最快完成的話，就要從小到大排序

struct a {
    long long t,et;
};
bool compare(struct a b,struct a c) {
    return b.t<c.t;
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    long long temp;
    long long total = 0;
    long long income = 0;
    cin>>n;
    struct a task[n];
    for (int i=0; i<n; i++) {
        cin>>temp;
        task[i].t = temp;
    }
    for (int i=0; i<n; i++) {
        cin>>temp;
        task[i].et = temp;
    }
    sort(task,task+n,compare);
    for (int i=0; i<n; i++) {
        total+=task[i].t;
        income+=task[i].et-total;
    }
    cout<<income<<endl;
    return 0;
}
