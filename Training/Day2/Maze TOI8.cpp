#include <bits/stdc++.h>
using namespace std;

// Shortest path

int m, n, sy, sx, ey, ex, a[159][159], dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
vector<vector<int>> dist1(159, vector<int>(159, 1e9)), dist2(159, vector<int>(159, 1e9));
queue<pair<int,int>> q;

void bfs(int sy, int sx, vector<vector<int>>& dist) {
	q.push({sy, sx});
	while (!q.empty()) {
		int y=q.front().first, x=q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 1 || yy > m || xx < 1 || xx > n) continue;
			if (a[yy][xx] == 0) {
				dist[yy][xx] = min(dist[yy][xx], dist[y][x]);
				continue;
			}
			if (dist[y][x]+1 < dist[yy][xx]) {
				dist[yy][xx] = dist[y][x]+1;
				q.push({yy, xx});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> m >> n >> sy >> sx >> ey >> ex;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	dist1[sy][sx] = dist2[ey][ex] = 1;
	bfs(sy, sx, dist1);
	bfs(ey, ex, dist2);
	int cnt=0, ans=1e9;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist1[i][j] == 1e9 || dist2[i][j] == 1e9) continue;
			ans = min(ans, dist1[i][j]+dist2[i][j]+1);
			cnt++;
		}
	}
	cout << cnt << "\n" << ans;
	return 0;
}