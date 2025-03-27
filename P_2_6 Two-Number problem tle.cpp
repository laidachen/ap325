#include <bits/stdc++.h>
#define LL long long
using namespace std;

int find(vector<LL> b,LL goal,int right) {
    int left = 0;
    while (left<=right) {
        int mid = (left+right)/2;
        if (b[mid]==goal) {
            return mid;
        } else if (b[mid]<goal) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    LL m,n,k,temp,goal,count;
    count = 0;
    goal = 0;
    vector<LL> a;
    vector<LL> b;
    cin>>m>>n>>k;
    for (int i=0; i<m; i++) {
        cin>>temp;
        a.push_back(temp);
    }
    for (int i=0; i<m; i++) {
        cin>>temp;
        b.push_back(temp);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int right = b.size()-1;
    for (int i=0; i<m; i++) {
        goal = k-a[i];
        int re = find(b,goal,right);
        if (re!=-1) {
            count++;
            right = re-1;
        }
    }
    cout<<count<<endl;
    return 0;
}