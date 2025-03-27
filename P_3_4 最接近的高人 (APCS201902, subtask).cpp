#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,temp;
    long long total = 1;
    vector<int> height;
    stack<int> tall;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>temp;
        height.push_back(temp);
    }
    tall.push(0);
    for (int i=1; i<n; i++) {
        while(height[i]>=height[tall.top()]) {//如果a[i]>a[i-1],代表前面不可能是後面的高人,所以可以刪掉前面小於a[i]的人
            tall.pop();
            if (tall.empty()) {
                break;
            }
        }
        if (tall.empty()) {
            total+=i+1;
        } else {
            total+=i-tall.top();
        }
        tall.push(i);//因為不知道後面的人會不會大於你,所以要加自己進去
    }
    cout<<total<<endl;
	return 0;
}