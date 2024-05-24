#include <bits/stdc++.h>
using namespace std;

vector<int> lis;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<int> h(n), l(n), r(n);
	for (auto& i : h) cin >> i;
	for (int i = 0; i < n; i++) {
		int idx=lower_bound(lis.begin(), lis.end(), h[i])-lis.begin();
		if (idx == lis.size()) lis.push_back(h[i]);
		else lis[idx] = h[i];
		l[i] = idx;
	}
	lis.clear();
	for (int i = n-1; i >= 0; i--) {
		int idx=lower_bound(lis.begin(), lis.end(), h[i])-lis.begin();
		if (idx == lis.size()) lis.push_back(h[i]);
		else lis[idx] = h[i];
		r[i] = idx;
	}
	while (q--) {
		int x;
		cin >> x;
		cout << min(l[x], r[x]) << "\n";
	}
	return 0;
}