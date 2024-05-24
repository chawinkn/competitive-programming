#include <bits/stdc++.h>
using namespace std;

#define ll long long

priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		pq.push(b-2*a);
	}
	ll sum=0, ans=-1e10;
	for (ll i = 1; i <= n; i++) {
		sum += pq.top(); pq.pop();
		ans = max(ans, sum-(n-i)*(n-i));
	}
	cout << ans;
	return 0;
}