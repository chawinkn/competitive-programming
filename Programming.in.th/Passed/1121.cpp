#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	string s;
	char t;
	cin >> q;
	while (q--) {
		stack<char> ss;
		cin >> s;
		for (auto i : s) {
			if (!ss.empty()) {
				t = ss.top();
				if ((t == '(' && i == ')') || (t == '[' && i == ']') || (t == '{' && i == '}')) {
					ss.pop();	
				}
				else ss.push(i);
			}
			else ss.push(i);
		}
		if (ss.empty()) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}
