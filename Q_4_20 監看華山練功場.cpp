#include <bits/stdc++.h>
using namespace std;

//�D�n�Q�k�O�γg�ߺt��k�A���ƧǵM��s�@�ӥk���I(x)�A�M��]�C�ӥ����I���p�󵥩�s���k���I���u�q��A���u�q���k�ݴ�ثe�s���k���I���ͳ̤j�Ȫ������u�A�����s�u�q�Ƹ�k���I���ȡA����k���I�j�󵥩�y�C


struct c {
    long long s,t;
};
bool compare(struct c a,struct c b) {
    return a.s<b.s;
}

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    int ok = 1;
    long long now = 0;
    long long y = 0;
    long long total = 0;
    long long lmax = 0;
    long long l = 0;
    long long maxs = 0;
    long long maxt = 0;
    long long temp,temp2;
    cin>>n;
    cin>>now>>y;
    struct c persons[n];
    for (int i=0; i<n; i++) {
        cin>>temp>>temp2;
        persons[i].s = temp;
        persons[i].t = temp2;
    }
    sort(persons,persons+n,compare);
    for (int i=0; i<n; i++) {
        if (now>=y) {
            lmax = 0;//�j��i��|�]�s���u�q
            break;
        }
        if (persons[i].s>now) {//�N������p�󵥩�k���I���u�q���]���F�A�n��s
            now = maxt;
            total++;
            lmax = 0;
            if (persons[i].s>now) {//�٬O�j��N�N����u�q�]�O�j��A�G�L��
                ok = 0;
                break;
            }
        }
        if (persons[i].t<=now) {//�p�G�k���I�p�󵥩�s���k���I�A�N��o���u�S��
            continue;
        }
        l = persons[i].t-now;
        if (l>lmax) {
            lmax = l;
            maxs = persons[i].s;
            maxt = persons[i].t;
        }
    }
    if (lmax!=0) {//�w���]���᪺���٨S��s
        total++;
        now = maxt;
    }
    if (now<y) {//�w���]���᪺���٬O�S�j�󵥩�y
        ok = 0;
    }
    if (ok) {
        cout<<total;
    } else {
        cout<<"-1";
    }
    return 0;
}
