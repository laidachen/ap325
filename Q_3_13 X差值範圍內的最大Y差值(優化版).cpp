#include <bits/stdc++.h>
#define LL long long
using namespace std;

//��deque�ӧ�s�϶��̤j�̤p�ȡA��u�ʷj���٧֡A������O(n^2)

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    LL l,temp;
    LL maximum = 0;
    LL total = 0;
    int n;
    int right = 0;
    vector<vector<LL>> a;
    vector<LL> add = {0,0};
    deque<int> maxy;
    deque<int> miny;
    maxy.push_back(0);
    miny.push_back(0);
    cin>>n>>l;
    for (int i=0; i<n; i++) {
        cin>>temp;
        add[0] = temp;
        a.push_back(add);
    }
    for (int i=0; i<n; i++) {
        cin>>temp;
        a[i][1] = temp;
    }
    sort(a.begin(),a.end());
    for (int left=0; left<n; left++) {
        if (right<left) {
            right = left;
        }
        //��W�X�϶���
        while (!maxy.empty()&&left>maxy.front()) {
            maxy.pop_front();
        }
        if (!maxy.empty()) {
            total = abs(a[maxy.front()][1]-a[left][1]);
            if (total>maximum) {
                maximum = total;
            }
        }
        while (!miny.empty()&&left>miny.front()) {
            miny.pop_front();
        }
        if (!miny.empty()) {
            total = abs(a[miny.front()][1]-a[left][1]);
            if (total>maximum) {
                maximum = total;
            }
        }

        while(right+1<n&&abs(a[right+1][0]-a[left][0])<=l) {
            right++;
            total = abs(a[right][1]-a[left][1]);
            //�p�Gi-1�p��i�N���|�O����϶��̪��̤j��
            while (!maxy.empty()&&a[right][1]>=a[maxy.back()][1]) {
                maxy.pop_back();
            }
            while (!miny.empty()&&a[right][1]<=a[miny.back()][1]) {
                miny.pop_back();
            }
            maxy.push_back(right);
            miny.push_back(right);
            if (total>maximum) {
                maximum = total;
            }
        }
    }
    cout<<maximum;
    return 0;
}
