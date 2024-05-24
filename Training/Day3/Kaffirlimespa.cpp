#include <bits/stdc++.h>
using namespace std;

// Greedy

#define ll long long

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll ans=0;
	for (int i = 0; i < n; i++) ans += a[i]*b[n-i-1];
	cout << ans;
	return 0;
}