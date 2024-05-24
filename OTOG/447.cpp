#include <bits/stdc++.h>
using namespace std;

// 80/100

#define T tuple<int,int,int>

int a[59][59], dy[]={0,-1,0,1}, dx[]={-1,0,1,0};
vector<vector<int>> dist1(59, vector<int>(59, 1e9)), dist2(59, vector<int>(59, 1e9));
priority_queue<T, vector<T>, greater<T>> pq;
vector<pair<int,int>> S;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] < 0) {
				a[i][j] *= -1;
				S.push_back({i, j});
			}
		}
	}
	int sy, sx, ey, ex;
	cin >> sy >> sx >> ey >> ex;
	pq.push({dist1[sy][sx]=0, sy, sx});
	while (!pq.empty()) {
		auto [d,y,x]=pq.top(); pq.pop();
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 1 || yy > n || xx < 1 || xx > n) continue;
			if (dist1[y][x]+a[yy][xx] < dist1[yy][xx]) {
				pq.push({dist1[yy][xx]=dist1[y][x]+a[yy][xx], yy, xx});
			}
		}
	}
	for (auto [y,x] : S) pq.push({dist2[y][x]=dist1[y][x], y, x});
	while (!pq.empty()) {
		auto [d,y,x]=pq.top(); pq.pop();
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 1 || yy > n || xx < 1 || xx > n) continue;
			if (dist2[y][x]+a[yy][xx] < dist2[yy][xx]) {
				pq.push({dist2[yy][xx]=dist2[y][x]+a[yy][xx], yy, xx});
			}
		}
	}
	cout << dist2[ey][ex];
	return 0;
}