#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

char arr[53][53];
queue<pair<int,int>> q;
vector<vector<int>> dist1(53, vector<int>(53, 1e3)), dist2(53, vector<int>(53, 1e3));
int dx[]={-1,0,1,0}, dy[]={0,-1,0,1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int r, c, sy, sx, ey, ex;
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '*') {
				dist1[i][j] = 0;
				q.push({i, j});
			}
			else if (arr[i][j] == 'S') {
				dist2[i][j] = 0;
				sy = i; sx = j;
			}
			else if (arr[i][j] == 'D') {
				ey = i; ex = j;
			}
		}
	}
	while (!q.empty()) { // water
		int y=q.front().f, x=q.front().s; q.pop();
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 1 || yy > r || xx < 1 || xx > c) continue;
			if (arr[yy][xx] != '.') continue;
			if (dist1[y][x]+1 < dist1[yy][xx]) {
				dist1[yy][xx] = dist1[y][x]+1;
				q.push({yy, xx});
			}
		}
	}
	q.push({sy, sx});
	while (!q.empty()) { // painter
		int y=q.front().f, x=q.front().s; q.pop();
		if (y == ey && x == ex) {
			cout << dist2[y][x];
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 1 || yy > r || xx < 1 || xx > c) continue;
			if (arr[yy][xx] == '*' || arr[yy][xx] == 'X') continue;
			if (dist2[y][x]+1 < dist1[yy][xx] && dist2[y][x]+1 < dist2[yy][xx]) {
				dist2[yy][xx] = dist2[y][x]+1;
				q.push({yy, xx});
			}
		}
	}
	cout << "KAKTUS\n";
	return 0;	
}
