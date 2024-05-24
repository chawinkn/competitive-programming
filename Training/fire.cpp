#include <bits/stdc++.h>
using namespace std;

vector<int> T[2009];
priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int v;
			cin >> v;
			T[i+j].push_back(v);
		}
	}
	int ans=0;
	for (int i = 2*n-2; i >= 1; i--) {
		for (auto v : T[i]) pq.push(v);
		if (pq.empty()) continue;
		ans += pq.top();
		pq.pop();
	}
	cout << ans;
	return 0;
}