#include <bits/stdc++.h>
using namespace std;

// Stack

void solve() {
	string s;
	cin >> s;
	stack<int> st;
	int ans=0;
	for (auto i : s) {
		if (i == 'H') st.push(1);
		else if (i == 'C') st.push(12);
		else if (i == 'O') st.push(16);
		else if (i == '(') st.push(-1);
		else if (i == ')') {
			int sum=0;
			while (!st.empty() && st.top() != -1) sum += st.top(), st.pop();
			st.pop(), st.push(sum);
		}
		else st.top() *= i-'0';
	}
	while (!st.empty()) ans += st.top(), st.pop();
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}
