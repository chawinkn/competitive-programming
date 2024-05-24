#include <bits/stdc++.h>
using namespace std;

int x[15009], y[15009], visited[15009];
vector<int> dist(15009, 1e9), mst;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	int u=0;
	while (mst.size() != n-1) {
		int mn=1e9, idx=0;
		visited[u] = true;
		for (int v = 0; v < n; v++) {
			if (visited[v]) continue;
			dist[v] = min(dist[v], abs(x[u]-x[v])+abs(y[u]-y[v]));
			if (dist[v] < mn) {
				mn = dist[v];
				idx = v;
			}
		}
		mst.push_back(mn);
		u = idx;
	}
	sort(mst.begin(), mst.end());
	int ans=0;
	for (int i = 0; i < n-k; i++) ans += mst[i];
	cout << ans;
	return 0;
}