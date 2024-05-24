#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<int>> start(1009, vector<int>(1009, 1e9));
int dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
ll cnt[2000009], qs[2000009], ans[2000009];
queue<pair<int,int>> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k, Q;
	cin >> n >> m >> k >> Q;
	for (int day = 1; day <= k; day++) {
		int r, c;
		cin >> r >> c;
		if (day < start[r][c]) start[r][c] = day, q.push({r, c});
		else qs[day]++;
		
		while (!q.empty()) {
			auto [y,x]=q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int yy=y+dy[i], xx=x+dx[i];
				if (yy < 0 || yy >= n || xx < 0 || xx >= m) continue;
				if (start[y][x]+1 < start[yy][xx]) {
					start[yy][xx] = start[y][x]+1;
					q.push({yy, xx});
				}
			} 
		}
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cnt[start[i][j]]++;
	ll sum=0;
	for (int i = 1; i <= 2000000; i++) {
		qs[i] += qs[i-1];	
		sum += cnt[i];
		ans[i] = ans[i-1]+sum;
	}
	while (Q--) {
		int d;
		cin >> d;
		cout << ans[d]+qs[d] << "\n";
//		ll ans=0;
//		for (int i = 1; i <= d; i++) ans += cnt[i]*(d-i+1);
//	    d = 1 cnt[1]*1 
// 		d = 2 cnt[1]*2 cnt[2]*1
// 		d = 3 cnt[1]*3 cnt[2]*2 cnt[3]*1	
//		cout << ans+qs[d] << "\n";
	}
	return 0;
}