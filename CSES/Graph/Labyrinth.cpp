#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int n, m, ex, ey, visited[1009][1009], dist[1009][1009], dx[]={0,1,0,-1}, dy[]={-1,0,1,0};
char path[]="URDL", p[1009][1009], ans[1000009];
queue<pair<int,int>> q;

int main() {
	char c;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c == '#') visited[i][j] = 1;
			else if (c == 'A') q.push({i, j});	
			else if (c == 'B') {
				ey = i; 
				ex = j;
			}
		}
	}
	while (!q.empty()) {
		int y=q.front().f, x=q.front().s;
		q.pop();
		if (visited[y][x]) continue;
		visited[y][x] = 1;
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 0 || yy >= n || xx < 0 || xx >= m) continue;
			if (visited[yy][xx]) continue;
			p[yy][xx] = path[i];
			dist[yy][xx] = dist[y][x]+1;
			q.push({yy, xx});
		}
	}
	if (visited[ey][ex]) {
		cout << "YES\n" << dist[ey][ex] << "\n";
		int y=ey, x=ex;
		for (int i = dist[ey][ex]; i >= 1; i--) {
			ans[i] = p[y][x];
			if (p[y][x] == 'U') y++;
			else if (p[y][x] == 'R') x--;
			else if (p[y][x] == 'D') y--;
			else if (p[y][x] == 'L') x++;
		}
		for (int i = 1; i <= dist[ey][ex]; i++) cout << ans[i];
	}
	else cout << "NO";
	return 0;
}
