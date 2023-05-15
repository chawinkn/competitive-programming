#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, l, k, c, num, sum, ans;
	cin >> n >> m >> l >> k >> c;
	sum = l*k*c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> num;
			sum += num;
		}
	}
	ans = sum/c;
	if (sum % c == 0) cout << ans;
	else cout << ans+1;
	return 0;
}
