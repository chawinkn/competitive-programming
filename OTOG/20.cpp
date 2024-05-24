#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int dist[59][59], dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
char arr[59][59];
vector<pair<int,int>> d;
queue<pair<int,int>> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, sx, sy;
	cin >> n >> m >> sx >> sy;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] >= 'A' && arr[i][j] <= 'Z') d.push_back({i, j});
			dist[i][j] = 1e9;
		}
	}
	dist[sy][sx] = 0;
	q.push({sy, sx});
	while (!q.empty()) {
		int y=q.front().f, x=q.front().s; q.pop();
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 0 || yy >= m || xx < 0 || xx >= n) continue;
			if (arr[yy][xx] == '1') continue;
			if (dist[y][x]+1 < dist[yy][xx]) {
				dist[yy][xx] = dist[y][x]+1;
				q.push({yy, xx});
			}
		}
	}
	vector<char> ans;
	int mn=1e9;
	for (auto i : d) mn = min(mn, dist[i.f][i.s]);			
	for (auto i : d) {
		if (dist[i.f][i.s] == mn) ans.push_back(arr[i.f][i.s]);
	}
	sort(ans.begin(), ans.end());
	for (auto i : ans) cout << i << "\n";
	return 0;
}