#include <bits/stdc++.h>
using namespace std;

vector<int> g[500009];
bool arr[500009], rock[500009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k, a, b, x, ans=1;
	cin >> n >> m >> k;
	while (m--) {
		cin >> a >> b;
		g[a].push_back(b);
	}
	while (k--) {
		cin >> x;
		rock[x] = true;
	}
	arr[1] = true;
	for (int i = 1; i <= n; i++) {
		if (!arr[i]) continue;
		ans = i;
		arr[i] = true;
		if (!rock[i]) arr[i+1] = true;
		for (auto j : g[i]) arr[j] = true;
	}
	if (ans == n) cout << 1;
	else cout << 0 << " " << ans;
	return 0;
}
