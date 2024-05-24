#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll qs[1000009], m=1e16, ans=-1e16;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> qs[i];
		qs[i] += qs[i-1];
	}
	for (int i = k; i <= n; i++) {
		m = min(m, qs[i-k]);
		ans = max(ans, qs[i]-m);
	}
	cout << ans;
	return 0;
}
