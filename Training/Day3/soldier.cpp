#include <bits/stdc++.h>
using namespace std;

// Heap

priority_queue<pair<pair<int,int>,int>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, r;
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int id, rank;
			cin >> id >> rank;
			pq.push({{rank, -i}, id});
		}
		else {
			if (pq.empty()) cout << -1;
			else {
				cout << pq.top().second;
				pq.pop();
			}
			cout << "\n";
		}
	}
	return 0;
}