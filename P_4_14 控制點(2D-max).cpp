#include <bits/stdc++.h>
using namespace std;

//x�y�иg�L�Ƨǫ�Ax�|���W�A�ҥH�i�H�P�_�ثe�o���I��y�y�ЬO�_�j��ε��󤧫e�������I��y�y�СA�����ܴN�i�H�R�����e���I��y�y�СA�M��O�o�n�[�ۤv�i�h
//�������e���ӧ�̪񪺰��H

struct xy {
    long long x,y;
};
bool compare(struct xy a,struct xy b) {
    if (a.x==b.x) {
        return a.y<b.y;//x�ۦP��y�p���n�\�e��
    }
    return a.x<b.x;
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    long long temp;
    cin>>n;
    struct xy dot[n];
    stack<long long> max;
    for (int i=0; i<n; i++) {
        cin>>temp;
        dot[i].x=temp;
    }
    for (int i=0; i<n; i++) {
        cin>>temp;
        dot[i].y=temp;
    }
    sort(dot,dot+n,compare);
    for (int i=0; i<n; i++) {
        while(!max.empty()&&dot[i].y>=max.top()) {
            max.pop();
        }
        max.push(dot[i].y);
    }
    cout<<max.size();
    return 0;
}
