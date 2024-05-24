#include <bits/stdc++.h>
using namespace std;

vector<int> g[69], visited(69);
queue<pair<int,int>> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m, s, i, a, b;
	cin >> m >> s >> i;
	while (m--) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	q.push({s, 0});
	visited[s] = true;
	while (!q.empty()) {
		auto [u, d]=q.front(); q.pop();
		if (u == i) {
			cout << d;
			break;
		}
		for (auto v : g[u]) {
			if (visited[v]) continue;
			visited[v] = true;
			q.push({v, d+1});
		}
	}
	return 0;
}