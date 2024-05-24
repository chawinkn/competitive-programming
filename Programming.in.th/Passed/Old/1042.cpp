#include <bits/stdc++.h>
using namespace std;

int cntx[5009], cnty[5009];

int main() {
	int n, m, k, x, y, r, ans=0;
	cin >> n >> m >> k;
	while (k--) {
		cin >> x >> y >> r;
		for (int i = x-r; i <= x+r; i++) {
			if (i < 0 || i > m) continue;
			cnty[i]++;	
		}
		for (int i = y-r; i <= y+r; i++) {
			if (i < 0 || i > n) continue;
			cntx[i]++;	
		}
	}
	for (int i = 0; i <= n; i++) ans = max(ans, cnty[i]);
	for (int i = 0; i <= m; i++) ans = max(ans, cntx[i]);
	cout << ans;
	return 0;
}
