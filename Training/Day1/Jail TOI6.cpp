#include <bits/stdc++.h>
using namespace std;

// Queue

queue<int> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) q.push(i);
	int cnt=1;
	while (!q.empty()) {
		int now=q.front(); q.pop();
		if (cnt == m) {
			cout << now << " ";
			cnt = 1;
		}
		else cnt++, q.push(now);
	}
	return 0;
}