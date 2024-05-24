#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

bool rock[39][39];
int dy[]={0,-1,0,1}, dx[]={-1,0,1,0};
queue<pair<int,int>> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	char c;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c;
			if (c == '.') continue;
			rock[i][j] = true;
			for (int k = 0; k < 4; k++) rock[i+dy[k]][j+dx[k]] = true;
		}
	}
	int ans=0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (rock[i][j]) continue;
			int cnt=0;
			rock[i][j] = true;
			q.push({i, j});
			while (!q.empty()) {
				int y=q.front().f, x=q.front().s; q.pop();
				cnt++;
				for (int i = 0; i < 4; i++) {
					int yy=y+dy[i], xx=x+dx[i];
					if (yy < 1 || yy > n || xx < 1 || xx > m) continue;
					if (rock[yy][xx]) continue;
					rock[yy][xx] = true;
					q.push({yy, xx});
				}
			}			
			ans = max(ans, cnt);
		}
	}
	cout << ans;
	return 0;
}
