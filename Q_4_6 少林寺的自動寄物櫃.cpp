#include <bits/stdc++.h>
using namespace std;

//�Ѫk�O�Ʊ�V���W�����Φ��ƶV�h�A�V���U�����q�V���A�N��w/f�V���W�ȶV�p�A�g�L�F���q�Ъ��ҩ���k�A�o�{�o�O�諸

struct tw {
    double w,f;
};
bool compare(struct tw a,struct tw b) {
    return (a.w/a.f)<(b.w/b.f);
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    double temp;
    long long total = 0;
    long long total2 = 0;
    cin>>n;
    struct tw a[n];
    for (int i=0; i<n; i++) {
        cin>>temp;
        a[i].w = temp;
    }
    for (int i=0; i<n; i++) {
        cin>>temp;
        a[i].f = temp;
    }
    sort(a,a+n,compare);
    total+=a[0].w;
    for (int i=1; i<n; i++) {
        total2+=total*a[i].f;
        total+=a[i].w;
    }
    cout<<total2;
    return 0;
}
