#include <bits/stdc++.h>
using namespace std;

char s[69][69];
int t[69][69], dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
bool visited[69][69];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int w, l;
	cin >> w >> l;
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> s[i][j];
			if (s[i][j] == 'T') t[i][j] = 1;
			t[i][j] += t[i-1][j]+t[i][j-1]-t[i-1][j-1];
		}
	}
	int a=0, ans=0;
	for (int k = 1; k <= min(w,l); k++) {
		int area=0, b=1e9;
		for (int i = k; i <= l; i++) {
			for (int j = k; j <= w; j++) {
				if (t[i][j]-t[i-k][j]-t[i][j-k]+t[i-k][j-k]) continue;
				int cnt=0;
				memset(visited, false, sizeof(visited));
				
				for (int r = i-k+1; r <= i; r++) {
					for (int c = j-k+1; c <= j; c++) {
						if (s[r][c] != 'P' || visited[r][c]) continue;
						cnt++;
						queue<pair<int,int>> q;
						q.push({r, c});
						visited[r][c] = true;
						while (!q.empty()) {
							auto [y,x]=q.front(); q.pop();
							for (int k = 0; k < 4; k++) {
								int yy=y+dy[k], xx=x+dx[k];
								if (yy < 1 || yy > l || xx < 1 || xx > w) continue;
								if (s[yy][xx] != 'P' || visited[yy][xx]) continue;
								visited[yy][xx] = true;
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
