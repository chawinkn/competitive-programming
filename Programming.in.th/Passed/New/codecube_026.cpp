#include <bits/stdc++.h>
using namespace std;

int cnt[1000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, a, b, ans=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		cnt[a]++; cnt[b]--;
	}
	for (int i = 1; i <= 1e6; i++) {
		cnt[i] += cnt[i-1];
		ans = max(ans, cnt[i]);
	}
	cout << ans;
	return 0;
}
