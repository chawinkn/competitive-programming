#include <bits/stdc++.h>
using namespace std;

int a[101][101], b[101][101];

int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) cin >> a[i][j];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) cin >> b[i][j];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) cout << a[i][j]+b[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
