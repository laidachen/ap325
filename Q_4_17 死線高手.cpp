#include <bits/stdc++.h>
using namespace std;

//死線越長的越往後排，如果死線相等前後不影響答案


struct a {
    long long t,dl;
};
bool compare(struct a b,struct a c) {
    return b.dl<c.dl;
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,t;
    cin>>t;
    for (int i=0; i<t; i++) {
        long long temp;
        long long total = 0;
        long long income = 0;
        int ok =1;
        cin>>n;
        struct a task[n];
        for (int i=0; i<n; i++) {
            cin>>temp;
            task[i].t = temp;
        }
        for (int i=0; i<n; i++) {
            cin>>temp;
            task[i].dl = temp;
        }
        sort(task,task+n,compare);
        for (int i=0; i<n; i++) {
            total+=task[i].t;
            if (task[i].dl<total) {
                cout<<"no"<<endl;
                ok = 0;
                break;
            }
        }
        if (ok) {
            cout<<"yes"<<endl;
        }
    }
    return 0;
}
