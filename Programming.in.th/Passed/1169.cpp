#include <bits/stdc++.h>
using namespace std;

stack<char> ss;

int main() {
	string s;
	cin >> s;
	for (auto i : s) {
		if (!ss.empty()) {
			if (ss.top() == '(' && i == ')') ss.pop();
			else ss.push(i);
		}
		else ss.push(i);
	}
	cout << ss.size();
	return 0;
}
