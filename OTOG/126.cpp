#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

pair<int,int> village[2009];
priority_queue<pair<int,int>> pq;
vector<int> dist(2009, 1e9);
bool visited[2009];

int main() {
	int n, m, k, a, b, N=0;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		char s[10009];
		scanf("%s", s);
		for (int j = 1; j <= m; j++) {
			if (s[j-1] == '.') continue;
			village[N+1] = {i, j};
			if (s[j-1] == 'A') a = N+1;
			else if (s[j-1] == 'B') b = N+1;
			N++;
		}
	}
	dist[a] = 0;
	pq.push({0, a});
	while (!pq.empty()) {
		auto [d,u]=pq.top(); pq.pop();
		if (visited[u]) continue;
		visited[u] = true;
		for (int v = 1; v <= N; v++) {
			if (u == v) continue;
			int w=abs(village[u].f-village[v].f)+abs(village[u].s-village[v].s);
			if (w <= k && dist[u]+w < dist[v]) {
				dist[v] = dist[u]+w;
				pq.push({-dist[v], v});
			}
		}
	}
	printf("%d", (dist[b] != 1e9 ? dist[b] : -1));
    return 0;
}