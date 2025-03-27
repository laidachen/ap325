#include <bits/stdc++.h>
using namespace std;

//+ 43 - 45 * 42 / 47

int main(void) {
	int num = 0;
	int value = 0;
	string s;
	stack<int> n;
	cin>>s;
	for (int i=0; i<s.size(); i++) {
		if (int(s[i])==43) {
			continue;
		} else if (int(s[i])==45) {//看到減把他看成負號相加
			i++;
			n.push(-1*(int(s[i])-48));
		} else if(int(s[i])==42) {
		    i++;
		    value = n.top();
		    n.pop();
		    n.push(value*(int(s[i])-48));
		} else if (int(s[i])==47) {
		    i++;
		    value = n.top();
		    n.pop();
		    n.push(value/(int(s[i])-48));
		} else {
		    n.push(int(s[i])-48);
		}
	}
	while(true) {
	    if (n.empty()) {
	        break;
	    } else {
	        num+=n.top();
	        n.pop();
	    }
	}
	cout<<num<<endl;
	return 0;
}