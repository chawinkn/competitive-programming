#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

char s[103][103];
int dist[103][103][4], dy[] = {0, -1, 0, 1}, dx[] = {-1, 0, 1, 0}; // L U R D

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int w, h, a, b, c;
	cin >> a >> b >> c >> w >> h;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> s[i][j];
			dist[i][j][0] = dist[i][j][1] = dist[i][j][2] = dist[i][j][3] = 1e9;
		}
	}
	queue<pair<int, int>> q;
	dist[h][0][2] = 0;
	q.push({h, 0});
	while (!q.empty()) {
		int y = q.front().f, x = q.front().s;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i], xx = x + dx[i];
			if (yy < 1 || yy > h || xx < 1 || xx > w) continue;
			for (int j = 0; j < 4; j++) {
				if (j == (i + 2) % 4) continue; // same direction
				int cost = dist[y][x][i] + ((i == j) ? a : b) + ((s[yy][xx] == 'X') ? c : 0);
				if (cost < dist[yy][xx][j])	{
					dist[yy][xx][j] = cost;
					q.push({yy, xx});
				}
			}
		}
	}
	cout << dist[1][w][2];
	return 0;
}
