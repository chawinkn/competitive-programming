#include <bits/stdc++.h>
using namespace std;

int x[2509], y[2509], dist[2509];
bool visited[2509];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int m, n, k;
	cin >> m >> n >> k;
	for (int i = 1; i <= k; i++) cin >> x[i] >> y[i];
	int u=1, cnt=0, ans=0;
	while (cnt != k-1) {
		int v, mx=0;
		visited[u] = true;
		for (int i = 1; i <= k; i++) {
			if (visited[i]) continue;
			dist[i] = max(dist[i], abs(x[i]-x[u])+abs(y[i]-y[u]));
			if (dist[i] > mx) {
				mx = dist[i];
				v = i;
			}
		}
		ans += mx;
		cnt++;
		u = v;
	}
	cout << ans;
	return 0;
}