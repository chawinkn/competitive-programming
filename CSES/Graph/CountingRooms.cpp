#include <bits/stdc++.h>
using namespace std;

int n, m, visited[1009][1009], dx[]={0,1,0,-1}, dy[]={-1,0,1,0};

void bfs(int y, int x) {
	if (visited[y][x]) continue;
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int yy=y+dy[i], xx=x+dx[i];
		if (yy < 0 || yy >= n || xx < 0 || xx >= m) continue;
		if (visited[yy][xx]) continue;
		bfs(yy, xx);
	}
}

int main() {
	char c;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c == '#') visited[i][j] = 1;
		}
	}
	int cnt=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
