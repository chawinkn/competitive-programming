#include <bits/stdc++.h>
using namespace std;

// Greedy

int a[1000009];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans=0;
	for (int l = 1, r = n; l < r; ) {
		if (a[l] == a[r]) l++, r--;
		else {
			ans++;
			if (a[l] > a[r]) a[r-1] += a[r], r--;
			else a[l+1] += a[l], l++;
		}
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}