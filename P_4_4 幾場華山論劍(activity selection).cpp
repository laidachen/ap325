#include <bits/stdc++.h>
using namespace std;

//�Ѫk�O�̧ǧ��̤p�k�ݪ��u�q�A�M��P�_�e�����ݬO�_��e�����k�q���|�A���O�N�[�@

struct be {//�ΨӦs�_�l�I�򵲧��I
    int s,t;
};
bool compare(struct be a,struct be b) {
    return a.t<b.t;
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,temp,temp2;
    int total = 1;
    cin>>n;
    struct be b[n];
    for (int i=0; i<n; i++) {
        cin>>temp>>temp2;
        b[i].s = temp;
        b[i].t = temp2;
    }
    sort(b,b+n,compare);
    int last = b[0].t;
    for (int i=1; i<n; i++) {
        if (b[i].s>last) {
            total++;
            last = b[i].t;
        }
    }
    cout<<total<<endl;
    return 0;
}
