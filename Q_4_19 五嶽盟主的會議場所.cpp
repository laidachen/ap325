#include <bits/stdc++.h>
using namespace std;

//�Ѫk�O��H�i�h���ɶ���X�h���ɶ������O�@�Өƥ�A�ҥH�u�n�O�O���O�X�h�٦��ɶ���H�ƴN�n�A�O�o���p�ۦP�ɶ��A�i�h�n���B�z

bool compare(vector<long long> a,vector<long long> b) {
    if (a[0]==b[0]) {
        return a[1]>b[1];//�i�h�n���B�z
    }
    return a[0]<b[0];
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    vector<vector<long long>> timeline;
    vector<long long> add;
    int n;
    long long temp,temp2,temp3;
    long long total = 0;
    long long max = 0;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>temp>>temp2>>temp3;
        add.push_back(temp2);
        add.push_back(1);
        add.push_back(temp);
        timeline.push_back(add);
        add.clear();
        add.push_back(temp3);
        add.push_back(0);
        add.push_back(temp);
        timeline.push_back(add);
        add.clear();
    }
    sort(timeline.begin(),timeline.end(),compare);
    for (int i=0; i<timeline.size(); i++) {
        if (timeline[i][1]==1) {
            total+=timeline[i][2];
        } else {
            total-=timeline[i][2];
        }
        if (total>max) {
            max = total;
        }
    }
    cout<<max;
    return 0;
}
