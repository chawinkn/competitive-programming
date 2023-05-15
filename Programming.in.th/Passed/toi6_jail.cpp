#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, cnt=1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) q.push(i);
	while (!q.empty()) {
		if (cnt != m) {
			q.push(q.front());	
			cnt++;
		}
		else {
			cout << q.front() << " ";
			cnt = 1;
		}
		q.pop();
	}
	return 0;
}
