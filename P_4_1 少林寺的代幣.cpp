#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int m;
    int temp;
    int total = 0;
    cin>>m;
    for (int i=0; i<m; i++) {
        cin>>temp;
        while (true) {
            if(temp==0) {
                break;
            }
            if (temp-50>=0) {
                temp-=50;
                total++;
            } else if (temp-10>=0) {
                temp-=10;
                total++;
            } else if (temp-5>=0) {
                temp-=5;
                total++;
            } else {
                temp-=1;
                total++;
            }
        }
        cout<<total<<endl;
        total = 0;
    }
    return 0;
}
