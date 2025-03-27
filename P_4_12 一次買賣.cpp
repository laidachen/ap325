#include <bits/stdc++.h>
using namespace std;

//只要想每天的最大獲利就好了，最大獲利是跟前面最小值相減，然後要維護好這個最小值

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    long long temp;
    long long total = 0;
    long long maxtotal = 0;
    vector<long long> price;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>temp;
        price.push_back(temp);
    }
    long long min = price[0];
    for (int i=1; i<n; i++) {
        if (price[i]<min) {
            min = price[i];
        }
        total = price[i]-min;
        if (total>maxtotal) {
            maxtotal = total;
        }
    }
    cout<<maxtotal;
    return 0;
}
