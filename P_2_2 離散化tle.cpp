#include <bits/stdc++.h>
using namespace std;

int binarysearch(vector<int> a,int goal) {
    int left = 0;
    int right = a.size()-1;
    int mid = 0;
    while (left<=right) {
        mid = (right+left)/2;
        if (a[mid]==goal) {
            return mid;
        } else {
            if (a[mid]<goal) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,temp,ok;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>temp;
        a.push_back(temp);
    }
    c = a;
    sort(c.begin(),c.end());
    b.push_back(c[0]);
    for (int i=0; i<n; i++) {
        if (c[i]!=b[b.size()-1]) {
            b.push_back(c[i]);
        }
    }
    for (int i=0; i<n; i++) {
        a[i] = binarysearch(b,a[i]);
    }
    for (int i=0; i<n; i++) {
        cout<<a[i];
        if (i!=n-1) {
            cout<<" ";
        }
    }
    return 0;
}