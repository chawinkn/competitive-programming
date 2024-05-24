#include <bits/stdc++.h>
using namespace std;

vector<int> g[100009];
int visited[100009];

void dfs(int u) {
	if (visited[u]) return;
	visited[u] = 1;
	for (auto i : g[u]) dfs(i);
}

int main() {
	int n, m, a, b;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int cnt=0;
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			ans.push_back(i);
			cnt++;
		}
	}
	cout << cnt-1 << "\n";	
	for (int i = 1; i < cnt; i++) {
		cout << ans[0] << " " << ans[i] << "\n";
	}
	return 0;
}
