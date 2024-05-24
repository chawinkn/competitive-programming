#include <bits/stdc++.h>
using namespace std;

// Quicksum 1D + Binary Search

int qs[500009], point[500009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		if (num >= 0) point[i] = num;
		else qs[i] = -num;
		point[i] += point[i-1], qs[i] += qs[i-1];
	}
	while (m--) {
		int x, h;
		cin >> x >> h;
		int idx=lower_bound(qs+x+1, qs+n+1, qs[x]+h)-qs-1;
		cout << point[idx]-point[x] << "\n";
	}
	return 0;
}