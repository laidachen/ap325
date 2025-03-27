#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,temp;
    long long total = 0;
    long long total2 = 0;
    vector<int> time;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>temp;
        time.push_back(temp);
    }
    sort(time.begin(),time.end());
    for (int i=0; i<n; i++) {
        total+=time[i];
        total2+=total;
    }
    cout<<total2<<endl;
    return 0;
}
