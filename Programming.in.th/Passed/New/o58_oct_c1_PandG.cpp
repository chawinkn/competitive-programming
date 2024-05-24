#include <bits/stdc++.h>
using namespace std;

int R, C, n, T, r, c, dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
string s[109];
queue<pair<int,int>> q;

void bfs(vector<vector<int>>& dist) {
	while (!q.empty()) {
		auto [y,x]=q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 0 || yy >= R || xx < 0 || xx >= C) continue;
			if (s[yy][xx] == '#') continue;
			if (dist[y][x]+1 < dist[yy][xx]) {
				dist[yy][xx] = dist[y][x]+1;
				q.push({yy, xx});
			}
		}
	}
}

void solve() {
	cin >> R >> C >> n >> T >> r >> c;
	vector<vector<int>> dist1(R, vector<int>(C, 1e9)), dist2(R, vector<int>(C, 1e9));
	for (int i = 1; i <= n; i++) {
		int ti, ri, ci;
		cin >> ti >> ri >> ci;
		dist1[ri][ci] = ti;
		q.push({ri, ci});
	}
	for (int i = 0; i < R; i++) cin >> s[i];
	bfs(dist1);
	dist2[r][c] = 0;
	q.push({r, c});
	bfs(dist2);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (s[i][j] == '#') continue;
			if (dist1[i][j] > T && dist2[i][j] <= T) {
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}