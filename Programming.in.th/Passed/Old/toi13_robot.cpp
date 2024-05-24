#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

char arr[2007][2007];
vector<vector<int>> dist(2007, vector<int>(2007, INT_MAX));
int dx[]={0,1,0,-1}, dy[]={-1,0,1,0};
queue<pair<int,int>> q;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'X') {
				q.push({i, j});
				dist[i][j] = 0;
			}
		}
	}
	while (!q.empty()) {
		int y=q.front().f, x=q.front().s;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 0 || yy >= n || xx < 0 || xx >= m) continue;
			if (arr[yy][xx] == 'W') continue;
			if (dist[y][x]+1 < dist[yy][xx]) {
				dist[yy][xx] = dist[y][x]+1;
				q.push({yy, xx});
			}
		}
	}
	int cnt=0, ans=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'A' && dist[i][j] != INT_MAX) {
				ans += 2*dist[i][j];
				cnt++;
			}
		}
	}
	cout << cnt << " " << ans;
	return 0;
}
