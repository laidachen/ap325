#include <bits/stdc++.h>
using namespace std;

//�u�n�Q�C�Ѫ��̤j��Q�N�n�F�A�̤j��Q�O��e���̤p�Ȭ۴�A�M��n���@�n�o�ӳ̤p��

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
