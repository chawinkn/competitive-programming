#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k, l;
	cin >> n >> m >> k >> l;
	vector<int> cannon(n);
	for (auto& i : cannon) cin >> i;
	while (k--) {
		int ans=0;
		auto L=cannon.begin(), R=cannon.begin();
		for (int i = 1; i <= m; i++) {
			int x;
			cin >> x;
			L=lower_bound(R, cannon.end(), x-l);
			R=upper_bound(R, cannon.end(), x+l);
			ans += R-L;
		}
		cout << ans << "\n";
	}
	return 0;	
}