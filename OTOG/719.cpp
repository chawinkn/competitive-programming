#include <bits/stdc++.h>
using namespace std;

int x[12349], y[12349], visited[12349];
vector<int> dist(12349, -1e9), mst;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	int u=0, cnt=0, ans=0;
	while (cnt != n-1) {
		int mx=-1e9, idx=0;
		visited[u] = true;
		cnt++;
		for (int v = 0; v < n; v++) {
			if (visited[v]) continue;
			dist[v] = max({dist[v], abs(x[u]-x[v]), abs(y[u]-y[v])});
			if (dist[v] > mx) {
				mx = dist[v];
				idx = v;
			}
		}
		ans += mx;
		u = idx;
	}
	cout << ans;
	return 0;
}