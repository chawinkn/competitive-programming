#include <bits/stdc++.h>
using namespace std;

// DSU

// sz (number of worker in section) cz (number of conflict worker with x in section)
int a[100009], b[100009], p[100009], sz[100009], cz[100009];
pair<int,int> E[200009];
vector<int> conflict, ask;
bool asked[200009];

int find(int u) {
	if (u == p[u]) return u;
	return p[u]=find(p[u]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		E[i] = {u, v};
	}
	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		if ((a[i] > a[x] && b[i] < b[x]) || (a[x] > a[i] && b[x] < b[i])) {
			// conflict.push_back(i);
			cz[i] = 1;
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int qi;
		cin >> qi;
		ask.push_back(qi);
		asked[qi] = true;
	}
	for (int i = 1; i <= m; i++) {
		if (asked[i]) continue;
		int u = find(E[i].first), v = find(E[i].second);
		if (u != v) p[u] = v, sz[v] += sz[u], cz[v] += cz[u];
	}
	vector<int> ans;
	reverse(ask.begin(), ask.end());
	// int xx = find(x), cnt=0;
	// for (auto i : conflict) {
	// 	int ii = find(i);
	// 	cnt += (xx == ii);
	// }
	// ans.push_back(sz[find(x)]-cnt-1);
	ans.push_back(sz[find(x)]-cz[find(x)]-1);
	for (auto i : ask) {
		int u = find(E[i].first), v = find(E[i].second);
		if (u != v) p[u] = v, sz[v] += sz[u], cz[v] += cz[u];
		// int xx = find(x), cnt=0;
		// for (auto i : conflict) {
		// 	int ii = find(i);
		// 	cnt += (xx == ii);
		// }
		// ans.push_back(sz[find(x)]-cnt-1);
		ans.push_back(sz[find(x)]-cz[find(x)]-1);
	}
	reverse(ans.begin(), ans.end());
	for (auto i : ans) cout << i << "\n";
	return 0;
}