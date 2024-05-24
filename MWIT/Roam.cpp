#include <bits/stdc++.h>
using namespace std;

int x[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		x[a]++, x[b+1]--;
	}
	for (int i = 1; i <= n; i++) x[i] += x[i-1];
	int q;
	cin >> q;
	while (q--) {
		int k;
		cin >> k;
		cout << x[k] << "\n";
	}
	return 0;
}