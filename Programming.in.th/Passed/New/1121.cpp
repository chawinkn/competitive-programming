#include <bits/stdc++.h>
using namespace std;

map<char,char> p;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	p[')'] = '(', p[']'] = '[', p['}'] = '{';
	while (n--) {
		string s;
		cin >> s;
		stack<char> st;
		for (auto i : s) {
			if (!st.empty() && p[i] == st.top()) st.pop();
			else st.push(i);
		}
		cout << (st.empty() ? "yes" : "no") << "\n";
	}
	return 0;	
}