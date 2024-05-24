#include <bits/stdc++.h>
using namespace std;

int t[29][29], dy[]={0,-1,0,1}, dx[]={-1,0,1,0};
queue<pair<int,int>> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m, x, y, ans;
	cin >> m >> x >> y;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) cin >> t[i][j];
	}
	q.push({y, x});
	while (!q.empty()) {
		auto [y,x]=q.front(); q.pop();
		ans = max(ans, t[y][x]);
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 1 || yy > m || xx < 1 || xx > m) continue;
			if (t[yy][xx] == 100) continue;
			if (t[yy][xx] > t[y][x]) q.push({yy, xx});
		}
	}
	cout << ans;
	return 0;
}