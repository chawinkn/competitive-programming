#include <bits/stdc++.h>
using namespace std;

// Quicksum 1D

int qs[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> qs[i], qs[i] += qs[i-1];
	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << qs[b]-qs[a-1] << "\n";
	}
	return 0;
}