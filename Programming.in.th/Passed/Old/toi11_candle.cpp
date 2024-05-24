#include <bits/stdc++.h>
using namespace std;

int dx[]={1, 0, -1, 1, -1, 1, 0, -1}, dy[]={1, 1, 1, 0, 0, -1, -1, -1}, v[2001][2001];
string arr[2001];
queue<pair<int, int>> q;

int main() {
	int m, n, cnt=0;
	cin >> m >> n;
	for (int i = 0; i < m; i++) cin >> arr[i];
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '1' && !v[i][j]) {
				cnt++;
				v[i][j] = 1;
				q.push({i, j});
				while (!q.empty()) {
					int f = q.front().first, s = q.front().second;
					q.pop();
					for (int k = 0; k < 8; k++) {
						int y = f+dy[k], x = s+dx[k];
						if (y >= 0 && y < m && x >= 0 && x < n && arr[y][x] == '1' && !v[y][x]) {
							v[y][x] = 1;
							q.push({y, x});	
						}
					}
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
