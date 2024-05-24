#include <bits/stdc++.h>
using namespace std;

bool visited[200009];
vector<int> g[200009];
int p[100009], cnt[100009];

int find(int u) {
	if (u == p[u]) return u;
	return p[u]=find(p[u]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) p[i] = i, cnt[i] = 1;
	while (m--) {
		int k, u, v;
		cin >> k >> u; k--;
		while (k--) {
			cin >> v;
			u=find(u), v=find(v);
			if (u == v) continue;
			if (cnt[u] > cnt[v]) {
				cnt[u] += cnt[v];
				p[v] = u;
			}
			else {
				cnt[v] += cnt[u];
				p[u] = v;
			}
		}
	}
	cout << cnt[find(0)];
	return 0;
}

//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL);
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < m; i++) {
//		int k;
//		cin >> k;
//		while (k--) {
//			int j;
//			cin >> j;
//			g[n+i].push_back(j); // n+i for group i
//			g[j].push_back(n+i);
//		}
//	}
//	queue<int> q;
//	int ans=1;
//	q.push(0);
//	visited[0] = true;
//	while (!q.empty()) {
//		auto u=q.front(); q.pop();
//		for (auto v : g[u]) {
//			if (visited[v]) continue;
//			visited[v] = true;
//			if (v < n) ans++;
//			q.push(v);
//		}
//	}
//	cout << ans;
//	return 0;
//}


//8 4
//3 2 4 3
//1 6
//4 1 6 5 7
//2 0 1