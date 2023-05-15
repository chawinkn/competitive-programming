#include <bits/stdc++.h>
using namespace std;

string s[1005];
int n, m, visited[1005][1005], ty, by, lx, rx;

void bfs(int i, int j) {
	if (visited[i][j]) return;
	visited[i][j] = 1;
	ty = max(ty, i);
	by = min(by, i);
	lx = min(lx, j);
	rx = max(rx, j);
	if (i-1 >= 0 && s[i-1][j] == '1') bfs(i-1, j);
	if (j+1 < n && s[i][j+1] == '1') bfs(i, j+1);
	if (i+1 < m && s[i+1][j] == '1') bfs(i+1, j);
	if (j-1 >= 0 && s[i][j-1] == '1') bfs(i, j-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int w, h, planet=0, star=0, comet=0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> s[i];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && s[i][j] == '1') {
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
