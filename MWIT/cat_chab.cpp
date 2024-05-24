#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	char t;
	deque<int> dq;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		if (t == 'A') dq.push_back(i);
		else dq.push_front(i);
	}
	while (!dq.empty()) {
		cout << dq.front() << " ";
		dq.pop_front();
	}
	return 0;
}
