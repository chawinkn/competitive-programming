#include <bits/stdc++.h>
using namespace std;

// Quicksum + Greedy ? + Binary Search

int p[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> p[i], p[i] += p[i-1];
	for (int i = n-1; i >= 1; i--) p[i] = min(p[i], p[i+1]);
	while (q--) {
		int c;
		cin >> c;
		cout << upper_bound(p+1, p+n+1, c)-p-1 << "\n";
	}
	// for (int i = 1; i <= n; i++) cout << p[i] << " ";
	return 0;
}