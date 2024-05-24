#include <bits/stdc++.h>
using namespace std;

// BFS, DFS

string a[2009];
int m, n, dx[]={-1,-1,0,1,1,1,0,-1}, dy[]={0,-1,-1,-1,0,1,1,1};

void bfs(int sy, int sx) {
	queue<pair<int,int>> q;
	q.push({sy, sx});
	while (!q.empty()) {
		int y=q.front().first, x=q.front().second; q.pop();
		for (int i = 0; i < 8; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 0 || yy >= m || xx < 0 || xx >= n) continue;
			if (a[yy][xx] == '0') continue;
			a[yy][xx] = '0';
			q.push({yy, xx});
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < m; i++) cin >> a[i];
	int ans=0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == '0') continue;
			ans++;
			bfs(i, j);
		}
	}
	cout << ans;
	return 0;
}