#include <bits/stdc++.h>
using namespace std;

//�C���I����e�����̤j�϶��M�ۥ[�A�]���n��X�o�I���̤j�϶��M�A���p�ۥ[��p��ۤv�A�N�N��϶��̤j�M�O�ۤv�A�ҥH�i�H��s

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
