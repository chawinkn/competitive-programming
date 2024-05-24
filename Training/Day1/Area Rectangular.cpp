#include <bits/stdc++.h>
using namespace std;

// Quicksum 2D

int qs[1009][1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int r, c;
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> qs[i][j];
			qs[i][j] += qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int i, j, k, l;
		cin >> i >> j >> k >> l; i++, j++, k++, l++;
		cout << qs[k][l]-qs[k][j-1]-qs[i-1][l]+qs[i-1][j-1] << "\n";
	}
	return 0;
}