#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll cnt[30009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, p, k;
	ll s;
	char e;
	cin >> n >> m;
	while (m--) {
		cin >> e;
		if (e == 'B') {
			cin >> p >> s;
			cnt[p] = s;
		}
		else {
			cin >> k;
			ll ans=0;
			for (int i = 1; i <= k; i++) ans=max(ans, cnt[i]);
			cout << ans << "\n";
		}
	}
	return 0;
}
