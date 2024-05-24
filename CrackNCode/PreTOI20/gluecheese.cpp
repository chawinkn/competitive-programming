#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define T tuple<ll,int,int>

int dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
int t[1009][1009];
vector<vector<ll>> dist(1009, vector<ll>(1009, 1e18));
priority_queue<T, vector<T>, greater<T>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, ci, cj;
	cin >> n >> m >> ci >> cj;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> t[i][j];
		}
	}
	pq.push({dist[ci][cj]=t[ci][cj], ci, cj});
	while (!pq.empty()) {
		auto [d,y,x]=pq.top(); pq.pop();
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 1 || yy > n || xx < 1 || xx > m) continue;
			if (dist[y][x]+t[yy][xx] < dist[yy][xx]) {
				pq.push({dist[yy][xx]=dist[y][x]+t[yy][xx], yy, xx});
			}
		}
	}
	ll e=min({dist[1][1], dist[1][m], dist[n][1], dist[n][m]});
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << e+dist[i][j]-t[ci][cj] << " ";
		}
		cout << "\n";
	}
	return 0;
}