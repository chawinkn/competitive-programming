#include <bits/stdc++.h>
using namespace std;

char arr[1009][1009];
int l[1009][1009], r[1009][1009], u[1009][1009], d[1009][1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k;
	cin >> k;
	while (k--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> arr[i][j];
				l[i][j] = r[i][j] = u[i][j] = d[i][j] = 0;
				if (arr[i][j] == '1') l[i][j] = r[i][j] = u[i][j] = d[i][j] = 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[i][j] == '0') continue;
				l[i][j] += l[i][j-1];
				u[i][j] += u[i-1][j];
			}
		}
		for (int i = n; i >= 1; i--) {
			for (int j = m; j >= 1; j--) {
				if (arr[i][j] == '0') continue;
				r[i][j] += r[i][j+1];
				d[i][j] += d[i+1][j];
			}
		}
		int ans=0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[i][j] == '0') continue;
				ans = max({ans, l[i][j]+u[i][j]-1, r[i][j]+u[i][j]-1, l[i][j]+d[i][j]-1, r[i][j]+d[i][j]-1});
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
