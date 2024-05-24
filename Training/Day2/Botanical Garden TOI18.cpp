#include <bits/stdc++.h>
using namespace std;

// DP, Greedy

int h[200009], l[200009], r[200009];
vector<int> lis, LIS;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		int idx=lower_bound(lis.begin(), lis.end(), h[i])-lis.begin();
		if (idx == (int)lis.size()) lis.push_back(h[i]);
		else lis[idx] = h[i];
		l[i] = idx;
	}
	for (int i = n-1; i >= 0; i--) {
		int idx=lower_bound(LIS.begin(), LIS.end(), h[i])-LIS.begin();
		if (idx == (int)LIS.size()) LIS.push_back(h[i]);
		else LIS[idx] = h[i];
		r[i] = idx;
	}
	while (q--) {
		int x;
		cin >> x;
		cout << min(l[x], r[x]) << "\n";
	}
	return 0;
}