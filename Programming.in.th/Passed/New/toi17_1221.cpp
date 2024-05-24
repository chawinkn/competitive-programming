#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int c[509];
pair<int,int> dist[509][509];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, q, a, b, C;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) dist[i][j] = {c[i]+c[j], 2};
	}
	while (m--) {
		cin >> a >> b >> C;
		dist[a][b] = dist[b][a] = {min(dist[a][b].f, C), 2};
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int d=dist[i][k].f+dist[k][j].f, cnt=dist[i][k].s+dist[k][j].s;
				if (d < dist[i][j].f) dist[i][j] = {d, cnt};
				else if (d == dist[i][j].f) dist[i][j].s = max(dist[i][j].s, cnt);
			}
		}
	}
	while (q--) {
		cin >> a >> b;
		cout << dist[a][b].f << " " << dist[a][b].s << "\n";
	}
	return 0;
}