#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define T tuple<ll,int,int>

vector<T> g[200009];
vector<vector<ll>> dist(200009, vector<ll>(19, 1e18));
priority_queue<T, vector<T>, greater<T>> pq;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n-1; i++) {
		int a, x, b;
		cin >> a >> x >> b;
		g[i].push_back({i+1, a, 0});
		g[i].push_back({x, b, 1});
	}
	ll ans=1e18;
	pq.push({dist[0][0]=0, 0, 0});
	while (!pq.empty()) {
		auto [d,u,ticket]=pq.top(); pq.pop();
		if (u == n-1) {
			ans = min(ans, dist[u][ticket]);
			continue;
		}
		for (auto [v,w,t] : g[u]) {
			if (ticket+t <= k && dist[u][ticket]+w < dist[v][ticket+t]) {
				pq.push({dist[v][ticket+t]=dist[u][ticket]+w, v, ticket+t});
			}
		}
	}
	cout << ans;
 	return 0;   
}