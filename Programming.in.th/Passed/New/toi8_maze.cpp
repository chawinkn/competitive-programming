#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;
int v[159][159];
vector<vector<int>> dist1(159, vector<int>(159, INF)), dist2(159, vector<int>(159, INF));
queue<pair<int,int>> q;
int dy[]={0,-1,0,1}, dx[]={-1,0,1,0};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, sy, sx, ey, ex;
	cin >> m >> n >> sy >> sx >> ey >> ex;	
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) cin >> v[i][j];
	}
	dist1[sy][sx] = 1;
	q.push({sy, sx});
	while (!q.empty()) {
		auto [y, x]=q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 1 || yy > m || xx < 1 || x > n) continue;
			if (!v[yy][xx]) {
				dist1[yy][xx] = min(dist1[yy][xx], dist1[y][x]);
				continue;	
			}
			if (dist1[y][x]+1 < dist1[yy][xx]) {
				dist1[yy][xx] = dist1[y][x]+1;
				q.push({yy, xx});
			}
		}
	}
	dist2[ey][ex] = 1;
	q.push({ey, ex});
	while (!q.empty()) {
		auto [y, x]=q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 1 || yy > m || xx < 1 || x > n) continue;
			if (!v[yy][xx]) {
				dist2[yy][xx] = min(dist2[yy][xx], dist2[y][x]);
				continue;	
			}
			if (dist2[y][x]+1 < dist2[yy][xx]) {
				dist2[yy][xx] = dist2[y][x]+1;
				q.push({yy, xx});
			}
		}
	}
	int cnt=0, ans=INF;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist1[i][j] == INF || dist2[i][j] == INF) continue;
			cnt++;
			ans = min(ans, dist1[i][j]+dist2[i][j]);
		}
	}
	cout << cnt << "\n" << ans+1;
	return 0;
}