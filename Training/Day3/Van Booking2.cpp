#include <bits/stdc++.h>
using namespace std;

// Heap

priority_queue<pair<int,int>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++) pq.push({0, -i});
	while (n--) {
		int t;
		cin >> t;
		int tt=pq.top().first, id=pq.top().second;
		tt *= -1, id *= -1;
		cout << id << "\n";
		pq.pop();
		pq.push({-(tt+t), -id});
	}
	return 0;
}