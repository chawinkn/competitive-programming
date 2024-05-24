#include <bits/stdc++.h>
using namespace std;

string s[1009];
int dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
queue<pair<int,int>> q;
bool flood[1009][1009], visited[1009][1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int r, c;
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		string ss;
		cin >> ss;
		ss = ' '+ss;
		s[i] = ss;
	}
	q.push({1, 1});
	flood[1][1] = true;
	while (!q.empty()) {
		auto [y,x]=q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 1 || yy > r || xx < 1 || xx > c) continue;
			if (flood[yy][xx] || s[yy][xx] == 'X') continue;
			flood[yy][xx] = true;
			q.push({yy, xx});
		}
	}
	int cnt, ans=0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (visited[i][j] || s[i][j] == '.') continue;
			q.push({i, j});
			visited[i][j] = true;
			cnt = 0;
			while (!q.empty()) {
				auto [y,x]=q.front(); q.pop();
				for (int i = 0; i < 4; i++) {
					int yy=y+dy[i], xx=x+dx[i];
					if (yy < 1 || yy > r || xx < 1 || xx > c) continue;
					if (flood[yy][xx]) cnt++;
					if (visited[yy][xx] || s[yy][xx] == '.') continue;
					visited[yy][xx] = true;
					q.push({yy, xx});
				}
			}
			ans = max(ans, cnt);
		}
	}
	cout << ans;
	return 0;
}