#include<bits/stdc++.h>
using namespace std;

char s[309][309];
vector<vector<vector<int>>> dist(309, vector<vector<int>>(309, vector<int>(8, 1e9)));
queue<tuple<int,int,int>> q;
int dx[]={0,1,1,1,0,-1,-1,-1}, dy[]={-1,-1,0,1,1,1,0,-1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int r, c, n;
	cin >> r >> c >> n;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> s[i][j];
			if (s[i][j] != 'J') continue;
			for (int k = 0; k < 8; k++) dist[i][j][k] = 0, q.push({i, j, k});	
		}
	}
	while (!q.empty()) {
		auto [y,x,d]=q.front(); q.pop();
		for (int i = 0; i < 8; i++) {
			if (i != d && i != (d+2)%8 && i != (d+6)%8) continue;
			int yy = y+dy[i], xx = x+dx[i];
			if (yy < 1 || yy > r || xx < 1 || xx > c || s[yy][xx] == '#') continue;
			if (dist[y][x][d]+(i!=d) < dist[yy][xx][i]) {
				dist[yy][xx][i] = dist[y][x][d]+(i!=d);
				q.push({yy, xx, i});
			}
		}
	}
	while (n--) {
		int y, x;
		cin >> y >> x;
		int ans=1e9;
		for (int i = 0; i < 8; i++) ans = min(ans, dist[y][x][i]);
		cout << (ans != 1e9 ? ans : -1) << "\n";
	}
	return 0;
}