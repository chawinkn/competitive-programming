#include <bits/stdc++.h>
using namespace std;

int dy[]={0,-1,0,1}, dx[]={-1,0,1,0};
char s[1009][1009];
vector<vector<int>> dist1(1009, vector<int>(1009, 1e9)), dist2(1009, vector<int>(1009, 1e9));
vector<pair<int,int>> C;
queue<pair<int,int>> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, ey, ex;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> s[i][j];
			if (s[i][j] == 'A') dist1[i][j] = 0, q.push({i, j});
			else if (s[i][j] == 'B') ey = i, ex = j;
			else if (s[i][j] == 'C') C.push_back({i, j});
		}
	}
	while (!q.empty()) {
		auto [y,x]=q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 0 || yy >= n || xx < 0 || xx >= m) continue;
			if (s[yy][xx] == '#') continue;
			if (dist1[y][x]+1 < dist1[yy][xx]) {
				dist1[yy][xx] = dist1[y][x]+1;
				q.push({yy, xx});
			}
		}
	}
	for (auto [y,x] : C) {
		dist2[y][x] = dist1[y][x];
		q.push({y, x});
	}
	while (!q.empty()) {
		auto [y,x]=q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 0 || yy >= n || xx < 0 || xx >= m) continue;
			if (s[yy][xx] == '#') continue;
			if (dist2[y][x]+1 < dist2[yy][xx]) {
				dist2[yy][xx] = dist2[y][x]+1;
				q.push({yy, xx});
			}
		}
	}
	cout << (dist2[ey][ex] != 1e9 ? dist2[ey][ex] : -1);
	return 0;
}