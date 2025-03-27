#include <bits/stdc++.h>
using namespace std;

/*�Q�����@���u���L�h�A�p�G�@�ӷs���쪺�u�q�����ݤj��ثe�u�q���k�ݡA
�N��o���u�q�򤧫᪺�u�q(���ƧǹL)���|����e���u�q���p���A
�ҥH�i�H��s���u�q�A�ܩ󥪺ݨS�j��ثe�k�ݡA�N��O�i�H���涰���u�q
�A�b�ݬݥL���k�ݦ��S���j��ثe���k�ݴN�n�F�A�����ܴN���W�h*/

struct line {
    long long left,right;
};
bool compare(struct line a,struct line b) {
    return a.left<b.left;
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    long long temp,temp2;
    long long ln = 0;
    long long rn = 0;
    long long total = 0;
    cin>>n;
    struct line l[n];
    for (int i=0; i<n; i++) {
        cin>>temp>>temp2;
        l[i].left = temp;
        l[i].right = temp2;
    }
    sort(l,l+n,compare);
    for (int i=0; i<n; i++) {
        if (l[i].left>rn) {
            total+=rn-ln;
            ln = l[i].left;
            rn = l[i].right;
            continue;
        }
        if (l[i].right>rn) {
            rn = l[i].right;
        }
    }
    total+=rn-ln;
    cout<<total;
    return 0;
}
