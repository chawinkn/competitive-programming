#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<tuple<int,int,int>> m;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		m.push_back({r, -l, i});
	}
	sort(m.begin(), m.end());
	vector<int> LIS, ans(n);
	for (auto [r,l,idx] : m) {
		l *= -1;
		auto it=upper_bound(LIS.begin(), LIS.end(), l, greater<int>());
		ans[idx] = it-LIS.begin()+1;
		if (it == LIS.end()) LIS.push_back(l);
		else *it = l;
	}
	int mx=0;
	for (auto i : ans) mx = max(mx, i);
	cout << mx << "\n";
	for (auto i : ans) cout << i << " ";
	return 0;
}