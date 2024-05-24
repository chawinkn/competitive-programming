#include <bits/stdc++.h>
using namespace std;

int m, n, t, arr[109][49], ans[109], dx[]={-1,0,1}, a[]={1,3,2};

void dfs(int y, int x) {
	if (y == t) {
		for (int i = 1; i <= t; i++) cout << ans[i] << "\n";
		return;
	}
	for (int i = 0; i < 3; i++) {
		int xx=x+dx[i];
		if (xx < 1 || xx > m) continue;
		if (arr[y+1][xx]) continue;
		ans[y+1] = a[i];
		dfs(y+1, xx);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> m >> n >> t;
	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= m; j++) cin >> arr[i][j];
	}
	dfs(0, n);
	return 0;
}
