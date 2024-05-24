#include <bits/stdc++.h>
using namespace std;

int a[1009][1009], dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
vector<vector<int>> mx(1009, vector<int>(1009, 1e6));
queue<pair<int,int>> q;

int main() {
	int n, ay=0, ax=0, by=0, bx=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) {
				if (!ay && !ax) ay = i, ax = j;
				else by = i, bx = j;
			} 
		}
	}
	mx[ay][ax] = 0;
	q.push({ay, ax});
	while (!q.empty()) {
		auto [y,x]=q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 1 || yy > n || xx < 1 || xx > n) continue;
			if (max(mx[y][x], a[yy][xx]) < mx[yy][xx]) {
				mx[yy][xx] = max(mx[y][x], a[yy][xx]);
				q.push({yy, xx});
			}
		}
	}
	cout << mx[by][bx];
    return 0;
}