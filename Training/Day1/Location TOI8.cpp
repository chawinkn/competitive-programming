#include <bits/stdc++.h>
using namespace std;

// Quicksum 2D

int qs[1009][1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m, n, k;
	cin >> m >> n >> k;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> qs[i][j];
			qs[i][j] += qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
		}
	}
	int ans=0;
	for (int i = k; i <= m; i++) {
		for (int j = k; j <= n; j++) {
			ans = max(ans, qs[i][j]-qs[i][j-k]-qs[i-k][j]+qs[i-k][j-k]);
		}
	}
	cout << ans;
	return 0;
}