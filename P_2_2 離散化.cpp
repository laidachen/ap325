#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,temp;
    vector<int> a;
    set<int> b;
    map<int,int> c;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>temp;
        a.push_back(temp);
    }
    for (int i=0; i<n; i++) {
        b.insert(a[i]);
    }
    int i = 0;
    for (auto it=b.begin(); it!=b.end(); it++) {
        c[*it] = i;
        i++;
    }
    for (int i=0; i<n; i++) {
        cout<<c[a[i]];
        if (i!=n-1) {
            cout<<" ";
        }
    }
    return 0;
}