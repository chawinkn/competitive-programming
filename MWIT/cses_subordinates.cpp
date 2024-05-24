#include <bits/stdc++.h>
using namespace std;

vector<int> g[200009];
int cnt[200009];

int size(int u) {
	if (!g[u].size()) return 1;
	for (auto i : g[u]) cnt[u] += size(i);
	return cnt[u]+1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, u;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> u;
		g[u].push_back(i);
	}
	size(1);
	for (int i = 1; i <= n; i++) cout << cnt[i] << " ";
	return 0;
}

