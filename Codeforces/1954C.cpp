#include <bits/stdc++.h>
using namespace std;

void solve() {
	string x, y;
	cin >> x >> y;
	int n=x.length();
	bool visited=false;
	for (int i = 0; i < n; i++) {
		if (x[i] == y[i]) continue;
		if (!visited) {
			if (x[i] < y[i]) swap(x[i], y[i]);
			visited = true;
		}
		else if (x[i] > y[i]) swap(x[i], y[i]);
	}
	cout << x << "\n" << y << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}