#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k, x, l, cnt=0;
	cin >> n >> m >> k >> l;
	for (int i = 1; i < m; i++) {
		cin >> x;
		cnt += x-l-1;
		pq.push(x-l-1);
		l = x;
	}
	while (k > 1 && !pq.empty()) {
		cnt -= pq.top();
		pq.pop();
		k--;
	}
	cout << cnt;
	return 0;
}