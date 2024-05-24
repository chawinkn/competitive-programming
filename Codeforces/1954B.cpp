#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int,int> mp;
	for (int i = 0; i < n; i++) cin >> a[i], mp[a[i]]++;
	if (mp.size() == 1) {
		cout << "-1\n";
		return;
	}
	int cnt=0, ans=n;
	for (int i = 0; i < n; i++) {
		if (a[i] == a[0]) cnt++;
		else ans = min(ans, cnt), cnt = 0;
	}
	cout << min(ans, cnt) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}