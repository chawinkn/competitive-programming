#include <bits/stdc++.h>
using namespace std;

// Toposort

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n+1);
	vector<int> in(n+1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		in[b]++;
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> topo;
	for (int i = 1; i <= n; i++) {
		if (!in[i]) pq.push(i);
	}
	while (!pq.empty()) {
		auto u=pq.top(); pq.pop();
		topo.push_back(u);
		for (auto v : g[u]) {
			in[v]--;
			if (!in[v]) pq.push(v);
		}
	}
	if (topo.size() != n) cout << "No";
	else {
		cout << "Yes ";
		for (auto i : topo) cout << i << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}