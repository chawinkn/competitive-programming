#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int arr[23][23], visited[23][23], dx[]={0,1,0,-1}, dy[]={-1,0,1,0};
queue<pair<int,int>> q;

int main() {
	int m, x, y, ans;
	cin >> m >> x >> y;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 100) visited[i][j] = 1;
		}
	}
	ans = arr[y][x];
	visited[y][x] = 1;
	q.push({y, x});
	while (!q.empty()) {
		y=q.front().f, x=q.front().s;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 1 || yy > m || xx < 1 || xx > m) continue;
			if (visited[yy][xx]) continue;
			visited[yy][xx] = 1;
			if (arr[yy][xx] > arr[y][x]) {
				ans = max(ans, arr[yy][xx]);
				q.push({yy, xx});	
			}
		}
	}
	cout << ans;
	return 0;
}
