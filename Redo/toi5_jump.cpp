#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	int ans=0;
	for (int i = 0; i < n; i++) {
		int idx=upper_bound(x.begin()+i, x.end(), x[i]+k)-x.begin();
		ans = max(ans, idx-i-1);
	}
	cout << ans;
	return 0;
}