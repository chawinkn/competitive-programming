#include <bits/stdc++.h>
using namespace std;

double c[5][5], ans=1e10;
int n, m, visited[5][5], dx[]={-1,-1,0,1,1,1,0,-1}, dy[]={0,-1,-1,-1,0,1,1,1};

void solve(int y, int x, double sum, int cnt) {
	sum += c[y][x];
	cnt++;
	if (cnt == n*m) {
		ans = min(ans, sum);
		return;
	}
	
	for (int i = 0; i < 8; i++) {
		int yy=y+dy[i], xx=x+dx[i];
		if (yy < 1 || yy > n || xx < 1 || xx > m) continue;
		c[yy][xx] += c[y][x]*0.1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visited[i][j]) continue;
			visited[i][j] = 1;
			solve(i, j, sum, cnt);
			visited[i][j] = 0;
		}
	}
	for (int i = 0; i < 8; i++) {
		int yy=y+dy[i], xx=x+dx[i];
		if (yy < 1 || yy > n || xx < 1 || xx > m) continue;
		c[yy][xx] -= c[y][x]*0.1;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> c[i][j];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			visited[i][j] = 1;
			solve(i, j, 0, 0);
			visited[i][j] = 0;	
		}
	}
	printf("%.2lf", ans);
	return 0;
}
