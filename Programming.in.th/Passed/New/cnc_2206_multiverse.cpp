#include <bits/stdc++.h>
using namespace std;

int g[100009];
bool visited[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int ans=0;
		for (int i = 1; i <= n; i++) cin >> g[i];
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= n; i++) {
			if (visited[i]) continue;
			int u=i, cnt=0;
			while (!visited[u]) {
				visited[u] = true;
				u = g[u], cnt++;
			}
			if (cnt == 1) ans = max(ans, 1);
			else if (cnt%2 == 0) ans = max(ans, 2);
			else ans = max(ans, 3);
		}
		cout << ans << "\n";
	}
	return 0;
}
