#include <bits/stdc++.h>
using namespace std;

//�Ѫk�O�Q���C���b�|���O�@���u�A�ݽu�\��C�@���I���ƶq�O�_<=k�A���|�ΤG���j�ӧ�A�����٭n���@�ӧP�_�O�_��������ơA�u�n�ΰj��P�_�N�n�F

int ok(int m,vector<long long>line,int k) {
    int total = 1;
    long long where = line[0];
    for (int i=0; i<line.size(); i++) {
        if (line[i]<=where+m) {
            continue;
        } else {
            total++;//�S�л\��N�n�A��@�ӽu�q�A�q����}�l
            where=line[i];
        }
    }
    if (total<=k) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;
    long long temp;
    long long r = 1000000000;
    long long l = 0;
    long long ans = 0;
    vector<long long> line;
    cin>>n>>k;
    for (int i=0; i<n; i++) {
        cin>>temp;
        line.push_back(temp);
    }
    sort(line.begin(),line.end());
    while(l<=r) {
        long long m = (r+l)/2;
        if (ok(m,line,k)) {
            ans = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
