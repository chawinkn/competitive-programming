#include <bits/stdc++.h>
using namespace std;

// Shortest path (MSSP)

string a[2009];
vector<vector<int>> dist(2009, vector<int>(2009, 1e9));
vector<pair<int,int>> target;
queue<pair<int,int>> q;
int dx[]={-1,0,1,0}, dy[]={0,-1,0,1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k=0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'A') k++, target.push_back({i, j});
			else if (a[i][j] == 'X') dist[i][j] = 0, q.push({i, j});
		}
	}
	while (!q.empty()) {
		int y=q.front().first, x=q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 0 || yy >= n || xx < 0 || xx >= m) continue;
			if (a[yy][xx] == 'W') continue;
			if (dist[y][x]+1 < dist[yy][xx]) {
				dist[yy][xx] = dist[y][x]+1;
				q.push({yy, xx});
			}
		}
	}
	int cnt=0, ans=0;
	for (int i = 0; i < k; i++) {
		int y=target[i].first, x=target[i].second;
		if (dist[y][x] != 1e9) ans += 2*dist[y][x], cnt++;
	}
	cout << cnt << " " << ans;
	return 0;
}