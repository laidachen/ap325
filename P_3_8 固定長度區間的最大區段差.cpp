 #include <bits/stdc++.h>
 using namespace std;
 
 int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,l;
    long long temp = 0;
    vector<long long> array;
    deque<long long> max;
    deque<long long> min;
    max.push_back(0);
    min.push_back(0);
    cin>>n>>l;
    for (int i=0; i<n; i++) {
        cin>>temp;
        array.push_back(temp);
    }
    temp = 0;
    for (int i=0; i<n; i++) {
        if (max.front()<i-(l-1)) {//每一動一格後面就會少一格，要判斷目前最大值有沒有出界
            max.pop_front();
        }
        while(!max.empty()&&array[i]>=array[max.back()]) {//如果array[i]大於前面，代表前面不會是之後區段裡面的最大值
            max.pop_back();
        }
        max.push_back(i);
        if (min.front()<i-(l-1)) {
            min.pop_front();
        }
        while(!min.empty()&&array[i]<=array[min.back()]) {//如果array[i]小於前面，代表前面不會是之後區段裡面的最小值
            min.pop_back();
        }
        min.push_back(i);
        if (array[max.front()]-array[min.front()]>temp) {
            temp = array[max.front()]-array[min.front()];
        }
    }
    cout<<temp;
    return 0;
 }