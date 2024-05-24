#include <bits/stdc++.h>
using namespace std;

int x[15009], y[15009], dist[15009];
bool visited[15009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		dist[i] = 1e9;	
	}
	vector<int> temp;
	int u=1;
	while (temp.size() != n-1) {
		int mn=1e9, v;
		visited[u] = true;
		for (int i = 1; i <= n; i++) {
			if (visited[i]) continue;
			dist[i] = min(dist[i], abs(x[i]-x[u])+abs(y[i]-y[u]));
			if (dist[i] < mn) {
				mn = dist[i];
				v = i;
			}
		}
		temp.push_back(mn);
		u = v;
	}
	sort(temp.begin(), temp.end());
	int ans=0;
	for (int i = 0; i < n-k; i++) ans += temp[i];
	cout << ans;
	return 0;
}