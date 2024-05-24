#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5+9;
int h[MAX_N], l[MAX_N], r[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q, x;
	cin >> n >> q;
	vector<int> lis;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
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
		cin >> x;
		cout << min(l[x], r[x]) << "\n";
	}
	return 0;
}
