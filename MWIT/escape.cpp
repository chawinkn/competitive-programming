#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

char arr[1009][1009];
int dist[1009][1009], dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
queue<pair<int,int>> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, sy, sx, ey, ex;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			dist[i][j] = 1e9;
			if (arr[i][j] == 'S') sy = i, sx = j;
			else if (arr[i][j] == 'F') {
				dist[i][j] = 0;
				q.push({i, j});
			}
		}
	}
	while (!q.empty()) {
		int y=q.front().f, x=q.front().s; q.pop();
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 1 || yy > n || xx < 1 || xx > m) continue;
			if (arr[yy][xx] == '#') continue;
			if (dist[y][x]+1 < dist[yy][xx]) {
				dist[yy][xx] = dist[y][x]+1;
				q.push({yy, xx});
			}
		}
	}
	int d=dist[sy][sx], ans=0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 'X' && dist[i][j] <= d) ans++;
		}
	}
	cout << ans;
	return 0;
}

