#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	cin >> s;
	stack<char> st;
	for (auto i : s) {
		if (!st.empty() && i == ')' && st.top() == '(') st.pop();
		else st.push(i);
	}
	cout << st.size();
	return 0;	
}