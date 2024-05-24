#include <bits/stdc++.h>
using namespace std;

int cnt[2000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		cnt[a]++;
	}
	int ans=0;
	for (int k = 1; k <= 2000000; k++) {
		int sum=0, team=0;
		for (int x = k; x <= 2000000; x+=k) {
			sum += k*cnt[x];
			team += cnt[x];
		}
		if (team >= 2) ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}