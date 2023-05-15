#include <bits/stdc++.h>
using namespace std;

int r, c, visited[31][31], cnt=0;
char arr[31][31];
vector<pair<int, int>> warp;

void bfs(int y, int x) {
	if (!visited[y][x]) {
		visited[y][x] = 1;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << visited[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		if (arr[y][x] == '*') cnt++;
		if (arr[y][x] == 'W') for (auto i : warp) bfs(i.first, i.second);	
		if (y >= 0 && (arr[y-1][x] == '.' || arr[y-1][x] == '*' || arr[y-1][x] == 'W')) bfs(y-1, x);
		if (x < c && (arr[y][x+1] == '.' || arr[y][x+1] == '*' || arr[y-1][x] == 'W')) bfs(y, x+1);
		if (y < r && (arr[y+1][x] == '.' || arr[y+1][x] == '*' || arr[y-1][x] == 'W')) bfs(y+1, x);
		if (x >= 0 && (arr[y][x-1] == '.' || arr[y][x-1] == '*' || arr[y-1][x] == 'W')) bfs(y, x-1);	
	}
}

int main() {
	int a, b;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'A') {
				a = i;
				b = j;
			}
			else if (arr[i][j] == 'W') warp.push_back({i, j});
		}
	}
	bfs(a, b);
	cout << cnt;
	return 0;
}
