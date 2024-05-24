#include <bits/stdc++.h>
using namespace std;

bool cmp(tuple<int,int,int> a, tuple<int,int,int> b) {
	auto [l1,r1,i1]=a; auto [l2,r2,i2]=b;
	if (r1 == r2) return l1 > l2;
	return r1 < r2;
}

int ans[400009];
vector<int> lis;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<tuple<int,int,int>> m(n);
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		m[i] = {l, r, i};
	}
	sort(m.begin(), m.end(), cmp);
	for (auto [l,r,i] : m) {
		auto it=upper_bound(lis.begin(), lis.end(), -l);
		if (it == lis.end()) {
			lis.push_back(-l);
			ans[i] = lis.size();
		}
		else {
			*it = -l;
			ans[i] = it-lis.begin()+1;
		}
	}
	int mx=0;
	for (int i = 0; i < n; i++) mx = max(mx, ans[i]);
	cout << mx << "\n";
	for (int i = 0; i < n; i++) cout << ans[i] << " ";
	return 0;
}