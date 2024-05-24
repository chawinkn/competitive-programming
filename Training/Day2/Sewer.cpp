#include <bits/stdc++.h>
using namespace std;

// BFS, DFS

char s[109][109];
int t[109][109], dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
bool visited[109][109];
queue<pair<int,int>> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) cin >> s[i][j];
	}
	t[1][1] = 1;
	q.push({1, 1});
	while (!q.empty()) {
		int y=q.front().first, x=q.front().second; q.pop();
		if (visited[y][x]) {
			cout << t[y][x] << "\n";
			cout << y << " " << x;
			break;
		}
		visited[y][x] = true;
		if ((s[y][x] == 'R' || s[y][x] == 'B') && x+1 <= b && !visited[y][x+1]) {
			t[y][x+1] = t[y][x]+1;
			q.push({y, x+1});
		}
		if ((s[y][x] == 'D' || s[y][x] == 'B') && y+1 <= a && !visited[y+1][x]) {
			t[y+1][x] = t[y][x]+1;
			q.push({y+1, x});
		}
		if ((s[y][x-1] == 'R' || s[y][x-1] == 'B') && x-1 >= 1 && !visited[y][x-1]) {
			t[y][x-1] = t[y][x]+1;
			q.push({y, x-1});
		}
		if ((s[y-1][x] == 'D' || s[y-1][x] == 'B') && y-1 >= 1 && !visited[y-1][x]) {
			t[y-1][x] = t[y][x]+1;
			q.push({y-1, x});
		}
	}
	return 0;
}