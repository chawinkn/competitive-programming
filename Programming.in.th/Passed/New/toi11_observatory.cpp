#include <bits/stdc++.h>
using namespace std;

int arr[2009][2009], tri1[2009][2009], tri2[2009][2009], dp1[2009][2009], dp2[2009][2009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m, n, k, ans=INT_MIN;
	cin >> m >> n >> k;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) cin >> arr[i][j];	
	}
	for (int i = 1; i <= m; i++) {
		int qs=0;
		for (int j = 1; j <= n; j++) {
			qs += arr[i][j];
			tri1[i][j] = tri1[i-1][j-1]+qs;
			dp1[i][j] = dp1[i-1][j]+dp1[i][j-1]-dp1[i-1][j-1]+arr[i][j];	
		}
	}
	for (int i = k; i <= m; i++) {
		for (int j = k; j <= n; j++) ans = max(ans, tri1[i][j]-tri1[i-k][j-k]-(dp1[i][j-k]-dp1[i-k][j-k]));
	}
	for (int i = 1; i <= m; i++) {
		int qs=0;
		for (int j = n; j >= 1; j--) {
			qs += arr[i][j];
			tri2[i][j] = tri2[i-1][j+1]+qs;
			dp2[i][j] = dp2[i-1][j]+dp2[i][j+1]-dp2[i-1][j+1]+arr[i][j];	
		}
	}
	for (int i = k; i <= m; i++) {
		for (int j = 1; j <= n-k+1; j++) ans = max(ans, tri2[i][j]-tri2[i-k][j+k]-(dp2[i][j+k]-dp2[i-k][j+k]));
	}
	cout << ans;
	return 0;
}
