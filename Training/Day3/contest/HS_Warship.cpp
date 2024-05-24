#include <bits/stdc++.h>
using namespace std;

// Greedy + Heap
// A B -> A-1 B-1
// Diff = (A+B)-(AB-A-B+1) = A+B-1
// Why do I sort by AB not A+B-1 during contest T_T

#define ll long long

void solve() {
	int n;
	ll k;
	cin >> n >> k;
	ll ans=0;
	priority_queue<pair<ll,pair<ll,ll>>> pq;
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		if (a == 1 || b == 1) ans += a*b;
		else pq.push({a+b-1, {a, b}});
	}
	while (!pq.empty() && k > 0) {
		ll a=pq.top().second.first, b=pq.top().second.second; pq.pop();
		if (a == 1 || b == 1) {
			ans += a*b;
			continue;
		}
		a--, b--, k--;
		pq.push({a+b-1, {a, b}});
	}
	while (!pq.empty()) {
		ll a=pq.top().second.first, b=pq.top().second.second; pq.pop();
		ans += a*b;
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}