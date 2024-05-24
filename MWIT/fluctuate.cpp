#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	int mn=1e6, ans=0;
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		ans = max(ans, p-mn);
		mn = min(mn, p);
	}
	cout << ans;
	return 0;
}