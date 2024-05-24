#include <bits/stdc++.h>
using namespace std;

int arr[2009][2009], x[10009], y[10009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, b, k, q, v, w;
	cin >> n >> m >> b >> k >> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> arr[i][j];
	}
	for (int i = 0; i < b; i++) cin >> y[i] >> x[i];
	while (q--) {
		cin >> v >> w;
		int cnt=0;
		for (int i = 0; i < b; i++) {
			if (abs(v-y[i])+abs(w-x[i]) <= k) cnt++;
		}
		cout << max(arr[v][w]-cnt, 0) << "\n";
	}
	return 0;
}
