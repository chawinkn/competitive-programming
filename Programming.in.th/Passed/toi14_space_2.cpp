#include <bits/stdc++.h>
using namespace std;

bitset<2005> s[10005], visited[10005];
int n, m, ty, by, lx, rx;
char c;

void bfs(int i, int j) {
	if (visited[i][j]) return;
	visited[i][j] = 1;
	ty = max(ty, i);
	by = min(by, i);
	lx = min(lx, j);
	rx = max(rx, j);
	if (i-1 >= 0 && s[i-1][j]) bfs(i-1, j);
	if (j+1 < n && s[i][j+1]) bfs(i, j+1);
	if (i+1 < m && s[i+1][j]) bfs(i+1, j);
	if (j-1 >= 0 && s[i][j-1]) bfs(i, j-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int w, h, planet=0, star=0, comet=0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++ ) {
			cin >> c;
			s[i][j] = c-'0';
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && s[i][j]) {
				ty = i; by = i; lx = j; rx = j;
				bfs(i, j);
				w = rx-lx+1;
				h = ty-by+1;
				if (w == h) {
					if (visited[by][lx] && visited[by][rx] && visited[ty][lx] && visited[ty][rx]) planet++;
					else star++;
				}
				else comet++;
			}
		}
	}
	cout << planet << " " << star << " " << comet;
	return 0;
}
