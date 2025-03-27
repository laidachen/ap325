#include <bits/stdc++.h>
using namespace std;

// ( 40 { 123 [ 91 ) 41 } 125 ] 93

void clear(stack<int>&l) {
    while(true) {
        if (l.empty()) {
            break;
        } else {
            l.pop();
        }
    }
}

int main(void) {
    map<int,int> find = {{40,1},{41,2},{91,3},{93,4},{123,5},{125,6}};//左括弧是奇數,又括弧是偶數
    stack<int> l;
    stack<int> r;
    int ok = 0;
    string s;
    while(cin>>s) {
        ok = 1;
        for (int i=0; i<s.size(); i++) {
            if (find[int(s[i])]%2==0) {//判斷是不是右括弧
                r.push(find[int(s[i])]);
                if (l.empty()) {
                    ok = 0;
                    r.pop();
                    break;
                } else {
                    if (r.top()-l.top()==1) {//判斷左右是不是一致
                        l.pop();
                        r.pop();
                        continue;
                    } else {
                        ok = 0;
                        r.pop();
                        clear(l);
                        break;
                    }
                }
            } else {
                l.push(find[int(s[i])]);
            }
        }
        if (l.empty()!=1) {
            ok = 0;
        }
        if (ok) {
            cout<<"yes"<<endl;
        } else {
            cout<<"no"<<endl;
        }
    }
    return 0;
}