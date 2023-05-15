#include <bits/stdc++.h>
using namespace std;

stack<char> s;

int main() {
	int n, ans;
	char c;
	cin >> n;
	while (n--) {
		cin >> c;
		if (!s.empty()) {
			if (c == s.top()) s.pop();
			else s.push(c);
		}
		else s.push(c);
	}
	ans = s.size();
	cout << ans << "\n";
	if (ans != 0) {
		while (!s.empty()) {
			cout << s.top();
			s.pop();
		}
	}
	else cout << "empty";
	return 0;
}
