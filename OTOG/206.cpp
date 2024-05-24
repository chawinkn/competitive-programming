#include <bits/stdc++.h>
using namespace std;

int arr[1009][1009], r[1009], c[1009];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, q, a, b;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			r[i] += arr[i][j];
			c[j] += arr[i][j];
		}
	}
	while (q--) {
		cin >> a >> b;
		cout << r[a]+c[b]-arr[a][b] << "\n";
	}
    return 0;
}