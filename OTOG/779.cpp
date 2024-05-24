#include <bits/stdc++.h>
using namespace std;

#define ll long long

priority_queue<ll> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	while (n--) {
		ll a;
		cin >> a;
		pq.push(-a);
	}
	ll ans=0;
	while (k--) {
		ll a=pq.top(); pq.pop();
		ans -= a;
		pq.push(a*1.05);
	}
	cout << ans;
	return 0;
}