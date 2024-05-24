#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

char arr[69][69];
int t[69][69], dx[]={-1,0,1,0}, dy[]={0,-1,0,1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int w, l, m;
	cin >> w >> l;
	m = max(w, l);
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'T') t[i][j] = 1;
			t[i][j] += t[i-1][j]+t[i][j-1]-t[i-1][j-1];
		}
	}
	int a=0, ans=0;
	for (int k = 1; k <= m; k++) {
		int area=0, b=1e5;
		for (int i = k; i <= l; i++) {
			for (int j = k; j <= w; j++) {
				if (t[i][j]-t[i-k][j]-t[i][j-k]+t[i-k][j-k]) continue;
				int cnt=0;
				vector<vector<bool>> visited(69, vector<bool>(69, false));
				
				for (int r = i-k+1; r <= i; r++) {
					for (int c = j-k+1; c <= j; c++) {
						if (arr[r][c] != 'P' || visited[r][c]) continue;
						cnt++;
						queue<pair<int,int>> q;
						q.push({r, c});
						while (!q.empty()) {
							int y=q.front().f, x=q.front().s; q.pop();
							if (visited[y][x]) continue;
							visited[y][x] = true;
							for (int k = 0; k < 4; k++) {
								int yy=y+dy[k], xx=x+dx[k];
								if (yy < 1 || yy > l || xx < 1 || xx > w) continue;
								if (arr[yy][xx] != 'P') continue;
								q.push({yy, xx});
							}
						}
					}
				}
				area = k*k;
				b = min(b, cnt);
			}
		}
		if (area > a) {
			a = area;
			ans = b;
		}
	}
	cout << a << " " << ans;
	return 0;
}
