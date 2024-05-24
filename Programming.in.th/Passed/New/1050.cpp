#include <bits/stdc++.h>
using namespace std;

map<vector<int>,int> mp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, p;
	cin >> n >> p;
	for (int i = 1; i <= n; i++) {
		vector<int> a(p);
		for (int j = 0; j < p; j++) cin >> a[j];
		mp[a] = i;
	}
	vector<int> t(p);
	for (int i = 0; i < p; i++) cin >> t[i];
	if (mp.find(t) != mp.end()) {
		cout << mp[t];
		return 0;	
	}
	for (auto [a,i] : mp) {
		vector<int> b(p);
		for (int j = 0; j < p; j++) b[j] = abs(a[j]-t[j]);
		if (mp.find(b) != mp.end() && a != b) {
			cout << min(i, mp[b]) << " " << max(i, mp[b]);
			return 0;
		}
	}
	cout << "NO";
	return 0;
}