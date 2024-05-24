#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5e5+9;
int qs[MAX_N], point[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, a, x, h;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (a >= 0) point[i] = a;
		else qs[i] = abs(a);
		point[i] += point[i-1], qs[i] += qs[i-1];
	}
	while (m--) {
		cin >> x >> h;
		int idx=lower_bound(qs+x+1, qs+n+1, qs[x]+h)-(qs+1);
		cout << point[idx]-point[x] << "\n";
	}
	return 0;
}
