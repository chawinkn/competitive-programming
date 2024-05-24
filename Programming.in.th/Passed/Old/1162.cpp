#include <bits/stdc++.h>
using namespace std;

int arr[103][43], m, n, t;

void dfs(int i, int j, string s) {
	if (i == t) {
		for (auto c : s) cout << c << "\n";
		return;
	}
	if (!arr[i+1][j-1] && j-1 >= 1) dfs(i+1, j-1, s+"1");
	if (!arr[i+1][j]) dfs(i+1, j, s+"3");
	if (!arr[i+1][j+1] && j+1 <= m) dfs(i+1, j+1, s+"2");
}

int main() {
	cin >> m >> n >> t;
	for (int i = 1; i <= t ; i++) {
		for (int j = 1; j <= m; j++) cin >> arr[i][j];
	}
	dfs(0, n, "");
	return 0;
}
