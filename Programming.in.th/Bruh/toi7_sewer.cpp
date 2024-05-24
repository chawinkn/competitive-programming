#include <bits/stdc++.h>
using namespace std;

char s[109][109];
int t[109][109], visited[109][109];
queue<pair<int,int>> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) cin >> s[i][j];
	}
	t[1][1] = 1;
	visited[1][1] = true;
	q.push({1, 1});
	while (!q.empty()) {
		auto [y,x]=q.front(); q.pop();
		if (t[y][x-1] == t[y-1][x] && visited[y][x-1] && visited[y-1][x]) {
			if (t[y][x] == t[y][x-1]+1 && (s[y][x-1] == 'B' || s[y][x-1] == 'R') && (s[y-1][x] == 'B' || s[y-1][x] == 'D')) {
				cout << t[y][x] << "\n";
				cout << y << " " << x;
				break;
			}
		}
		if ((s[y][x] == 'B' || s[y][x] == 'R') && x+1 <= b) {
			if (visited[y][x+1]) continue;
			visited[y][x+1] = true;
			t[y][x+1] = t[y][x]+1;
			q.push({y, x+1});
		}
		if ((s[y][x] == 'B' || s[y][x] == 'D') && y+1 <= a) {
			if (visited[y+1][x]) continue;
			visited[y+1][x] = true;
			t[y+1][x] = t[y][x]+1;
			q.push({y+1, x});
		}
	}
	return 0;
}