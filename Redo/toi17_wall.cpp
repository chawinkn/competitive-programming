#include <bits/stdc++.h>
using namespace std;

string s[1009];
int dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
bool flood[1009][1009], visited[1009][1009];
queue<pair<int,int>> q;

int main() {
   	ios_base::sync_with_stdio(false); cin.tie(NULL);
   	int n, m;
   	cin >> n >> m;
   	for (int i = 0; i < n; i++) cin >> s[i];
   	q.push({0, 0});
   	flood[0][0] = true;
   	while (!q.empty()) {
   		auto [y,x]=q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 0 || yy >= n || xx < 0 || xx >= m) continue;
			if (s[yy][xx] == 'X' || flood[yy][xx]) continue;
			flood[yy][xx] = true;
			q.push({yy, xx});
		}
	}
	int ans=0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (s[i][j] == '.' || visited[i][j]) continue;
		int cnt=0;
		q.push({i, j});
		visited[i][j] = true;
		while (!q.empty()) {
			auto [y,x]=q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int yy=y+dy[i], xx=x+dx[i];
				if (yy < 0 || yy >= n || xx < 0 || xx >= m) continue;
				if (flood[yy][xx]) {
					cnt++;
					continue;
				}
				if (s[yy][xx] == '.' || visited[yy][xx]) continue;
				visited[yy][xx] = true;
				q.push({yy, xx});
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
   	return 0;
}