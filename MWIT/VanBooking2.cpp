#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int,int>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++) pq.push({0, -i});
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		auto [s,id]=pq.top(); pq.pop();
		s *= -1, id *= -1;
		cout << id << "\n";
		s += t;
		pq.push({-s, -id});
	}
	return 0;
}