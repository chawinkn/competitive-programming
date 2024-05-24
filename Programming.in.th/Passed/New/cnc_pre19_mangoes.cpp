#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int dp[5007][5007];
pair<pair<int,int>,int> t[100007];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, row, col;
	cin >> n >> m >> row >> col;
	for (int i = 0; i < n; i++) cin >> t[i].f.f >> t[i].f.s >> t[i].s;
	for (int i = 0; i < m; i++) {
		int tr, tc;
		cin >> tr >> tc;
		dp[tr][tc] = 1;
	}
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			dp[i][j] += dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1];
		}
	}
	
	int l=1, r=max(row, col);
	while (l < r) {
		int d = (l+r)/2;
		bool check=true;
		for (int i = 0; i < n; i++) {
			int y=t[i].f.f, x=t[i].f.s, w=t[i].s;
			int y1=max(y-d-1, 0), x1=max(x-d-1, 0), y2=min(y+d, row), x2=min(x+d, col);
			if (dp[y2][x2]-dp[y2][x1]-dp[y1][x2]+dp[y1][x1] < w) {
				check = false;
				break;
			}
		}
		if (check) r = d;
		else l = d+1;
	}
	cout << l;
	return 0;
}
