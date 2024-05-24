#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int arr[23][23], visited[23][23], dx[]={-1,0,1,0}, dy[]={0,-1,0,1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m, sx, sy, ans=-1e5;
	cin >> m >> sx >> sy;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 100) visited[i][j] = 1;
		}
	}
	queue<pair<int,int>> q;
	visited[sy][sx] = true;
	q.push({sy, sx});
	while (!q.empty()) {
		int y=q.front().f, x=q.front().s; q.pop();
		ans = max(ans, arr[y][x]);
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 1 || yy > m || xx < 1 || xx > m) continue;
			if (visited[yy][xx]) continue;
			if (arr[yy][xx] <= arr[y][x]) continue;
			visited[yy][xx] = true;
			q.push({yy, xx});
		}
	}
	cout << ans;
	return 0;
}
