#include <bits/stdc++.h>
using namespace std;

int arr[309][309], l[309][309], r[309][309], u[309][309], d[309][309];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			l[i][j] = r[i][j] = u[i][j] = d[i][j] = arr[i][j];
			if ((i+j)%2 == 1) l[i][j] = r[i][j] = u[i][j] = d[i][j] = -arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			l[i][j] += l[i][j-1];
			u[i][j] += u[i-1][j];
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {
			r[i][j] += r[i][j+1];
			d[i][j] += d[i+1][j];
		}
	}
	int ans=0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int sum=l[i][j-1]-l[i][max(0,j-k-1)]+r[i][j+1]-r[i][min(m+1,j+k+1)]+u[i-1][j]-u[max(0,i-k-1)][j]+d[i+1][j]-d[min(n+1,i+k+1)][j];
			if ((i+j)%2 == 1) sum *= -1;
			ans = max(ans, sum+arr[i][j]);
		}
	}
	cout << ans;
	return 0;
}
