#include <bits/stdc++.h>
using namespace std;

int arr[1009][1009];

int main() {
	int n, m, x, y, r, ans;
	cin >> n >> m;
	while (n--) {
		cin >> x >> y;
		arr[x][y] = 1;
	}
	while (m--) {
		cin >> x >> y >> r;
		ans = 0;
		for (int i = x-r; i <= x+r; i++) {
			for (int j = y-r; j <= y+r; j++) {
				if (i < 0 || i > 1000 || j < 0 || j > 1000) continue;
				if (arr[i][j]) {
					arr[i][j] = 0;
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}