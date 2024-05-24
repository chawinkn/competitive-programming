#include <bits/stdc++.h>
using namespace std;

#define ll long long

int a[69];
bool x[69];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> x[i];
	ll ans=0;
	vector<pair<ll,int>> v;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (x[i]) ans += 1ll<<i;
		else v.push_back({-(1ll<<i), a[i]});
	}
	sort(v.begin(), v.end());
	for (auto [s,c] : v) {
		if (k >= c) {
			ans -= s;
			k -= c;
		}
	}
	cout << ans;
	return 0;
}