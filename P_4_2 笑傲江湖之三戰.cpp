#include <bits/stdc++.h>
using namespace std;

/*解法是找出我方攻擊力最接近且超過敵方其中一人攻擊力的那一個，
兩邊攻擊力都先排序，就會從最小的開始找，因為只要目標敵人攻擊力大於我方的攻擊力，
那之後敵人攻擊力越大，那人攻擊力也沒用，
所以可以先排序之後用一根指針跑到最接近且不超過的位置*/

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,temp;
    int point = -1;
    int win = 0;
    vector<int> enemy;
    vector<int> myside;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>temp;
        enemy.push_back(temp);
    }
    for (int i=0; i<n; i++) {
        cin>>temp;
        myside.push_back(temp);
    }
    sort(enemy.begin(),enemy.end());
    sort(myside.begin(),myside.end());
    for (int i=0; i<n; i++) {
        while(point+1<n&&myside[point+1]<=enemy[i]) {
            point++;
        }
        if (point+1==n) {
            break;
        } else {
            point++;
            win++;
        }
    }
    cout<<win;
    return 0;
}
