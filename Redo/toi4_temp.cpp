#include <bits/stdc++.h>
using namespace std;

int t[29][29], dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
queue<pair<int,int>> q;
bool visited[29][29];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m, sx, sy;
	cin >> m >> sx >> sy;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) cin >> t[i][j];
	}
	int ans=0; 
	q.push({sy, sx});
	visited[sy][sx] = true;
	while (!q.empty()) {
		auto [y,x]=q.front(); q.pop();
		ans = max(ans, t[y][x]);
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 1 || yy > m || xx < 1 || xx > m) continue;
			if (t[yy][xx] == 100 || t[yy][xx] <= t[y][x] || visited[yy][xx]) continue;
			visited[yy][xx] = true;
			q.push({yy, xx});
		}
	}
	cout << ans;
	return 0;
}