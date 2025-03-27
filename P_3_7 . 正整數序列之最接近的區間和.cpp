#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    int l = 1;
    int r = 0;
    int num = 1;
    LL sum = 0;
    LL sumn = 0;
    LL k,temp;
    vector<LL> array;
    cin>>n>>k;
    for (int i=0; i<n; i++) {
        cin>>temp;
        sum+=temp;
        array.push_back(sum);
    }
    while (true) {
        if (r+1>=n || array[r+1]>k) {
            sumn=array[r];
            break;
        }
        r++;
    }
    for (int i=r+1; i<n; i++) {
        while(true) {
            if (array[i]-array[l-1]>k) {//接近不超過，不會有等號
                l++;
            } else {
                break;
            }
        }
        if (array[i]-array[l-1]>sumn) {
            sumn=array[i]-array[l-1];
            num = 1;
        } else if (array[i]-array[l-1]==sumn) {
            num+=1;
        }
    }
    cout<<sumn<<endl;
    cout<<num<<endl;
    return 0;
}