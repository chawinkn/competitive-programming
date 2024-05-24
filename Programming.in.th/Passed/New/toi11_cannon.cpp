#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k, L, x;
	cin >> n >> m >> k >> L;
	while (n--) {
		cin >> x;
		arr.push_back(x);
	}
	while (k--) {
		auto l=arr.begin(), r=arr.begin();
		int ans=0;
		for (int i = 0; i < m; i++) {
			cin >> x;
			l = lower_bound(r, arr.end(), x-L);
			r = upper_bound(r, arr.end(), x+L);
			ans += r-l;
			cout << l-arr.begin() << " " << r-arr.begin() << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}