#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<pair<int,int>> g[100007];
vector<int> dist(100007, -1), visited(100007);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x, y, z;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> x >> y >> z;
		g[x].push_back({y, z});
		g[y].push_back({x, z});
	}
	priority_queue<pair<int,int>> pq;
	dist[1] = 0;
	pq.push({0, 1});
	while (!pq.empty()) {
		int u=pq.top().s;
		pq.pop();
		if (visited[u]) continue;
		visited[u] = 1;
		
		for (auto i : g[u]) {
			int v=i.f, w=i.s;
			if (!visited[v] && dist[u]+w > dist[v]) {
				dist[v] = dist[u]+w;
				pq.push({dist[v], v});
			}
		}
	}
	int ans=0;
	for (int i = 1; i <= n; i++) ans = max(ans, dist[i]);
	cout << ans;
	return 0;
}
