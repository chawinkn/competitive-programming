#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	cin >> s;
	deque<char> dq;
	for (auto i : s) {
		if (dq.empty() || dq.back() != i) dq.push_back(i);
		else dq.pop_back();
	}
	while (!dq.empty()) {
		cout << dq.front();
		dq.pop_front();
	}
	return 0;
}