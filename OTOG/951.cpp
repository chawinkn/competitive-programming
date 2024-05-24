#include <bits/stdc++.h>
using namespace std;

stack<int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	cin >> s;
	int i=0, n=s.length();
	while (i < n) {
		if (s[i] == 'T') {
			string sn;
			i++;
			while (i < n && s[i] >= '0' && s[i] <= '9') {
				sn += s[i];
				i++;
			}
			int num=0;
			for (auto i : sn)  {
				num *= 10;
				num += i-'0';
			}
			st.push(num);
		}
		else if (s[i] == 'P') {
			st.pop();
			i++;	
		}
		else if (s[i] == 'B') {
			cout << st.top() << "\n";
			i++;	
		}
		else {
			int a=st.top(); st.pop();
			int b=st.top(); st.pop();
			if (s[i] == 'A') st.push(a+b);
			else if (s[i] == 'S') st.push(a-b);
			else st.push(a*b);
			i++;
		}
	}
	return 0;
}