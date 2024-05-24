#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k, a, b, sum;
	cin >> n >> m >> k;
	cin >> a;
	for (int i = 1; i < m; i++) {
		cin >> b;
		pq.push(b-a-1);
		sum += b-a-1; // good box
		a = b;
	}
	while (k > 1 && !pq.empty()) {
		sum -= pq.top();
		pq.pop();
		k--;
	}
	cout << sum;
	return 0;
}
