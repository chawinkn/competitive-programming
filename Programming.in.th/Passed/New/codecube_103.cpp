#include <bits/stdc++.h>
using namespace std;

int cnt[1000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, p, a, b, ans=1000009;
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		cnt[min(a, b)]++; cnt[max(a+1, b+1)]--;	
	}
	for (int i = 0; i <= 1e6; i++) {
		if (i > 0) cnt[i] += cnt[i-1];
		if (cnt[i] == n) ans = min(ans, abs(i-p));
	}
	if (ans != 1000009) cout << ans;
	else cout << -1;
	return 0;
}
