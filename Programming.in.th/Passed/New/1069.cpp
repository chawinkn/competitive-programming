#include <bits/stdc++.h>
using namespace std;

stack<char> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	char c;
	cin >> n;
	while (n--) {
		cin >> c;
		if (!s.empty() && s.top() == c) s.pop();
		else s.push(c);
	}
	cout << s.size() << "\n";
	if (!s.empty()) {
		while (!s.empty()) {
			cout << s.top();
			s.pop();
		}
	}
	else cout << "empty";
	return 0;
}
