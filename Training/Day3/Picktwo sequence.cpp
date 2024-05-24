#include <bits/stdc++.h>
using namespace std;

// DP, Greedy

void solve() {
	int n;
	cin >> n;
	vector<int> a(n+9), l(n+9), r(n+9);
	int sum=0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum = max(a[i], sum+a[i]);
		l[i] = max(l[i-1], sum);
	}
	sum = 0;
	for (int i = n; i >= 1; i--) {
		sum = max(a[i], sum+a[i]);
		r[i] = max(r[i+1], sum);
	}
	int ans=0;
	for (int i = 1; i <= n; i++) ans = max(ans, l[i]+r[i+1]);
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}