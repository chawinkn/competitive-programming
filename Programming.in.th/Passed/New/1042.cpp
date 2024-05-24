#include <bits/stdc++.h>
using namespace std;

int qsx[5009], qsy[5009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	while (k--) {
		int x, y, r;
		cin >> x >> y >> r;
		qsx[max(0, x-r)]++, qsx[min(m, x+r+1)]--;
		qsy[max(0, y-r)]++, qsy[min(n, y+r+1)]--;
	}
	int ans=0;
	for (int i = 0; i <= m; i++) qsx[i] += qsx[i-1], ans = max(ans, qsx[i]);
	for (int i = 0; i <= n; i++) qsy[i] += qsy[i-1], ans = max(ans, qsy[i]);
	cout << ans;
	return 0;
}