#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dist(2009, vector<int>(2009, 1e9));
char s[2009][2009];
queue<pair<int,int>> q;
int dy[]={0,-1,0,1}, dx[]={-1,0,1,0};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> s[i][j];
			if (s[i][j] == 'X') {
				dist[i][j] = 0;
				q.push({i, j});
			}
		}
	}
	while (!q.empty()) {
		auto [y,x]=q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 0 || yy >= n || xx < 0 || xx >= m) continue;
			if (s[yy][xx] == 'W') continue;
			if (dist[y][x]+1 < dist[yy][xx]) {
				dist[yy][xx] = dist[y][x]+1;
				q.push({yy, xx});
			}
		}
	}
	int cnt=0, ans=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'A' && dist[i][j] != 1e9) {
				cnt++;
				ans += dist[i][j];
			}
		}
	}
	cout << cnt << " " << ans*2;
	return 0;
}