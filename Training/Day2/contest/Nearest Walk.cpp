#include <bits/stdc++.h>
using namespace std;

// Shortest path

int dx[]={-1,0,1,0}, dy[]={0,-1,0,1};

void solve() {
	int r, c;
	cin >> r >> c;
	vector<vector<int>> dist(r, vector<int>(c, 1e9));
	string s[r+1];
	queue<pair<int,int>> q;
	int ey, ex;
	for (int i = 0; i < r; i++) {
		cin >> s[i];
		for (int j = 0; j < c; j++) {
			if (s[i][j] == 'A') dist[i][j] = 0, q.push({i, j});
			else if (s[i][j] == 'B') ey = i, ex = j;
		}
	}
	while (!q.empty()) {
		int y=q.front().first, x=q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 0 || yy >= r || xx < 0 || xx >= c) continue;
			if (s[yy][xx] == '#') continue;
			if (dist[y][x]+1 < dist[yy][xx]) {
				dist[yy][xx] = dist[y][x]+1;
				q.push({yy, xx});
			}
		}
	}
	cout << (dist[ey][ex] != 1e9 ? dist[ey][ex] : -1) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}