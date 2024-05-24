#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, u, v;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<pair<int,int>> a;
		for (int i = 0; i < n; i++) {
			cin >> u >> v;
			a.push_back({u, 1});
			a.push_back({v+1, -1});
		}		
		sort(a.begin(), a.end());
		int cnt=0;
		string ans="yes";
		for (auto i : a) {
			cnt += i.second;
			if (cnt == n) ans = "no";
		}
		cout << ans << "\n";
	}
	return 0;
}