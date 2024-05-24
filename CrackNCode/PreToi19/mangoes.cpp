#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

pair<int,int> t[100003], s[100003];
int w[100003];

// 49/100 points

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, row, col;
	cin >> n >> m >> row >> col;
	for (int i = 0; i < n; i++) cin >> t[i].f >> t[i].s >> w[i];
	for (int i = 0; i < m; i++) cin >> s[i].f >> s[i].s;
	int l=1, r=max(row, col);
	while (l < r) {
		int d=(l+r)/2;
		vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
		for (int i = 0; i < m; i++) {
			for (int j = max(1, s[i].f-d); j <= min(row, s[i].f+d); j++) {
				dp[j][max(1, s[i].s-d)]++;
				if (s[i].s+d+1 > col) continue;
				dp[j][s[i].s+d+1]--;
			}
		}
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {	
				dp[i][j] += dp[i][j-1];
			}
		}
		bool valid=true;
		for (int i = 0; i < n; i++) {
			if (dp[t[i].f][t[i].s] < w[i]) {
				valid = false;
				break;
			}
		}
		if (valid) r = d;
		else l = d+1;
	}
	cout << l;
	return 0;
}
