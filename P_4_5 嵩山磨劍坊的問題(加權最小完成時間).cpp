#include <bits/stdc++.h>
using namespace std;

//�o�D�Ѫk�O�̨θѪ�t/w�@�w�|�p��U�@��w/t���ȡA�M��ڳo�D��struct�s���ܼ�,�M��۰��ƧǥX�̤p��,�]����Ƹ��Ƭ۰��u�|�O���,�ҥH�ίB�I�ƨӸ�,�M��double����פ����
//�o�D���e�ۭ��|���ít/w<t2/w2-->t*w2<t2*w

struct tw {
    double t,w;
};
bool compare(struct tw a,struct tw b) {
    return (a.t/a.w)<(b.t/b.w);
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
        a[i].t = temp;
    }
    for (int i=0; i<n; i++) {
        cin>>temp;
        a[i].w = temp;
    }
    sort(a,a+n,compare);
    for (int i=0; i<n; i++) {
        total+=a[i].t;
        total2+=total*a[i].w;
    }
    cout<<total2;
    return 0;
}
