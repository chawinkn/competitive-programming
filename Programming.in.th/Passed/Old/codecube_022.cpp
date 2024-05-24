#include <bits/stdc++.h>
using namespace std;

int v[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x, y, cnt=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (!v[x][y]) {
			v[x][y] = 1;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
