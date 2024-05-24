#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int arr[109][109], dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};
string ans="NESW";

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k, a, b;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			arr[i][j]--;	
		}
	}
	while (k--) {
		cin >> b >> a;
		vector<vector<bool>> visited(109, vector<bool>(109, false));
		queue<pair<int,int>> q;
		q.push({a, b});
		while (!q.empty()) {
			int y=q.front().f, x=q.front().s; q.pop();
			if (visited[y][x]) {
				cout << "NO\n";
				break;
			}
			visited[y][x] = true;
			int yy=y+dy[arr[y][x]], xx=x+dx[arr[y][x]];
			if (yy < 1 || yy > n || xx < 1 || xx > m) {
				cout << ans[arr[y][x]] << "\n";
				break;
			}
			q.push({yy, xx});
		} 
	}
	return 0;
}
