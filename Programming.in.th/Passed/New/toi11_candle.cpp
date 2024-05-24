#include <bits/stdc++.h>
using namespace std;

string s[2009];
queue<pair<int,int>> q;
int dx[]={-1,-1,0,1,1,1,0,-1}, dy[]={0,-1,-1,-1,0,1,1,1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, ans=0;
	cin >> m >> n;
	for (int i = 0; i < m; i++) cin >> s[i];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] == '0') continue;
			ans++, s[i][j] = '0', q.push({i, j});
			while (!q.empty()) {
				auto [y, x]=q.front(); q.pop();
				for (int i = 0; i < 8; i++) {
					int yy=y+dy[i], xx=x+dx[i];
					if (yy < 0 || yy >= m || xx < 0 || xx >= n) continue;
					if (s[yy][xx] == '0') continue;
					s[yy][xx] = '0';
					q.push({yy, xx});
				}
			}
		}
	}
	cout << ans;
	return 0;
}