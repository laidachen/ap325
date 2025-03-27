#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,temp;
    long long total = 0;
    vector<int> h;
    vector<int> p;
    deque<int> tall = {0};
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>temp;
        h.push_back(temp);
    }
    for (int i=0; i<n; i++) {
        cin>>temp;
        p.push_back(temp);
    }
    for (int i=1; i<n; i++) {
        while (h[i]>=h[tall.back()]) {//找比自己高的人
            tall.pop_back();
            if (tall.empty()) {
                break;
            }
        }
        if (tall.empty()) {
            total+=i;
            tall.push_back(i);
        } else {//判斷加椅子高度有沒有大於前面的人
            int where = -1;
            for (int i2=tall.size(); i2>0; i2=i2/2) {//用二分搜找到最近的比自己高的人,記得要先偵測有沒有越界
                while (where+i2<tall.size() && h[tall[where+i2]]>h[i]+p[i]) {
                    where+=i2;
                }
            }
            if (where==-1) {
                total+=i;
                tall.push_back(i);
            } else {
                total+=i-tall[where]-1;
                tall.push_back(i);
            }
        }
    }
    cout<<total<<endl;
	return 0;
}