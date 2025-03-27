#include <bits/stdc++.h>
using namespace std;

//每個點都跟前面的最大區間和相加，因為要算出這點的最大區間和，假如相加後小於自己，就代表區間最大和是自己，所以可以更新

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    long long temp;
    long long maxtotal = 0;
    vector<long long> price;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>temp;
        price.push_back(temp);
    }
    long long total = price[0];
    for (int i=1; i<n; i++) {
        if (total+price[i]>price[i]) {
            total+=price[i];
        } else {
            total = price[i];
        }
        if (total>maxtotal) {
            maxtotal = total;
        }
    }
    cout<<maxtotal;
    return 0;
}
