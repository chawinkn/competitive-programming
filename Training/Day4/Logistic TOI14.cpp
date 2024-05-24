#include <bits/stdc++.h>
using namespace std;

// Shortest path on State

#define pii pair<int,int>
#define T tuple<int,int,int,int>

vector<pii> g[10009];
vector<vector<vector<int>>> dist(109, vector<vector<int>>(109, vector<int>(3, 1e9)));
priority_queue<T, vector<T>, greater<T>> pq;
int p[109];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	int s, d, F, m;
	cin >> s >> d >> F >> m;
	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}
	pq.push(make_tuple(dist[s][0][0]=0, s, 0, 0));
	while (!pq.empty()) {
		int d, u, f, ticket;
		tie(d, u, f, ticket) = pq.top(); pq.pop();
		if (f < F && dist[u][f][ticket]+p[u] < dist[u][f+1][ticket]) {
			pq.push(make_tuple(dist[u][f+1][ticket]=dist[u][f][ticket]+p[u], u, f+1, ticket));
		}
		if (!ticket && dist[u][f][ticket] < dist[u][F][ticket+1]) {
			pq.push(make_tuple(dist[u][F][ticket+1]=dist[u][f][ticket], u, F, ticket+1));
		}
		for (auto i : g[u]) {
			int v=i.first, w=i.second;
			if (f >= w && dist[u][f][ticket] < dist[v][f-w][ticket]) {
				pq.push(make_tuple(dist[v][f-w][ticket]=dist[u][f][ticket], v, f-w, ticket));
			}
		}
	}
	cout << dist[d][F][1];
	return 0;
}