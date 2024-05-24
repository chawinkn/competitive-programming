#include <bits/stdc++.h>
using namespace std;

// BFS, DFS

int dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
string s[1009];
bool flood[1009][1009], visited[1009][1009];
queue<pair<int,int>> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++) cin >> s[i];
	flood[0][0] = true;
	q.push({0, 0});
	while (!q.empty()) {
		int y=q.front().first, x=q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 0 || yy >= r || xx < 0 || xx >= c) continue;
			if (s[yy][xx] == 'X' || flood[yy][xx]) continue;
			flood[yy][xx] = true;
			q.push({yy, xx});
		}
	}
	int ans=0;
	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
		if (s[i][j] == '.' || visited[i][j]) continue;
		int cnt=0;
		visited[i][j] = true;
		q.push({i, j});
		while (!q.empty()) {
			int y=q.front().first, x=q.front().second; q.pop();
			for (int i = 0; i < 4; i++) {
				int yy=y+dy[i], xx=x+dx[i];
				if (yy < 0 || yy >= r || xx < 0 || xx >= c) continue;
				if (flood[yy][xx]) cnt++;
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