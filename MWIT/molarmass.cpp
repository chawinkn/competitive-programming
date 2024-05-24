#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	stack<int> st;
	for (auto i : s) {
		if (i == '(') st.push(-1);
		else if (i == ')') {
			int sum=0;
			while (!st.empty() && st.top() != -1) {
				sum += st.top();
				st.pop();
			}
			st.pop();
			st.push(sum);
		}
		else if (i >= '2' && i <= '9') {
			int res=st.top();
			st.pop();
			st.push(res*(i-'0'));
		}
		else if (i == 'H') st.push(1);
		else if (i == 'C') st.push(12);
		else if (i == 'O') st.push(16);
	}
	int ans=0;
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}