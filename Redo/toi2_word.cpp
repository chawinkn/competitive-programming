#include <bits/stdc++.h>
using namespace std;

string board[29];
int dx[]={-1,-1,0,1,1,1,0,-1}, dy[]={0,-1,-1,-1,0,1,1,1};
queue<tuple<int,int,int,int>> q;

bool same(char a, char b) {
	return tolower(a) == tolower(b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m, n, k;
	cin >> m >> n;
	for (int i = 0; i < m; i++) cin >> board[i];
	cin >> k;
	while (k--) {
		string s;
		cin >> s;
		int l=s.length();
		while (!q.empty()) q.pop();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!same(board[i][j], s[0])) continue;
				for (int d = 0; d < 8; d++) q.push({i, j, 0, d});
			}
		}
		while (!q.empty()) {
			auto [y,x,k,d]=q.front(); q.pop();
			if (k == l-1) {
				cout << y-dy[d]*(l-1) << " " << x-dx[d]*(l-1) << "\n";
				break;
			}
			int yy=y+dy[d], xx=x+dx[d];
			if (yy < 0 || yy >= m || xx < 0 || xx >= n) continue;
			if (!same(board[yy][xx], s[k+1])) continue;
			q.push({yy, xx, k+1, d});
		}
	}
	return 0;
}