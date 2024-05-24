#include <bits/stdc++.h>
using namespace std;

int g[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q, n;
	cin >> q;
	while (q--) {
		cin >> n;
		int ans=0;
		for (int i = 1; i <= n; i++) cin >> g[i];
		for (int i = 1; i <= n; i++) {
			if (g[i] == -1) continue; // visited
			int u=g[i], cnt=1;
			while (u != i) {
				int now=u;
				u = g[u];
				g[now] = -1;
				cnt++;
			}
			if (cnt == 1) ans = max(ans, 1);
			else if (cnt%2 == 0) ans = max(ans, 2);
			else ans = max(ans, 3);
		}
		cout << ans << "\n";
	}
	return 0;
}
