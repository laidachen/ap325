#include <bits/stdc++.h>
#define LL long long
using namespace std;

//�������O�����k��즳�����C�⪺�϶��A���U�ӨC���k�@�B�N�������w���k��ּe��

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    set<LL> s;
    map<LL,int> m;
    vector<LL> a;
    int num[200000] = {0};
    int color = 0;
    int gcolor = 0;
    int left = 0;
    int n;
    LL temp;
    cin>>n;
    int length = n;
    //�����ơA�]���C��|��10^9��
    for (int i=0; i<n; i++) {
        cin>>temp;
        a.push_back(temp);
        s.insert(temp);
    }
    int i=0;
    for (auto it=s.begin(); it!=s.end(); it++) {
        m[*it] = i;
        i++;
    }
    gcolor = i;
    for (int r=0; r<n; r++) {
        if (num[m[a[r]]]+1==1) {
            color++;
        }
        num[m[a[r]]]+=1;
        while(color>=gcolor) {
            if (num[m[a[left]]]-1==0) {
                color--;
            }
            num[m[a[left]]]-=1;
            if (color<gcolor) {//�N����ֱ��o��
                num[m[a[left]]]+=1;
                color++;
                break;
            } else {
                left++;//�i�H�ֱ��o��
            }
        }
        if (r-left+1<length&&color>=gcolor) {//�ثe�m�a�����C��ƭn�j��ε���ؼ��C��ơA�~���i�h���׸̭�
            length = r-left+1;
        }
    }
    cout<<length;
    return 0;
}
