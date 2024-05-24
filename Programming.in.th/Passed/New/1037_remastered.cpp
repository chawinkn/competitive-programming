#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

char arr[53][53];
queue<pair<pair<int,int>,int>> q;
int dx[]={-1,0,1,0}, dy[]={0,-1,0,1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int r, c, sy, sx, ey, ex;
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '*') q.push({{i, j}, 0});
			else if (arr[i][j] == 'S') {
				sy = i; sx = j;
			}
			else if (arr[i][j] == 'D') {
				ey = i; ex = j;
			}
		}
	}
	q.push({{sy, sx}, 0});
	while (!q.empty()) {
		int y=q.front().f.f, x=q.front().f.s, t=q.front().s; q.pop();
		if (y == ey && x == ex) {
			cout << t;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy < 1 || yy > r || xx < 1 || xx > c) continue;
			if (arr[y][x] == '*' && arr[yy][xx] == '.') {
				arr[yy][xx] = '*';
				q.push({{yy, xx}, t+1});
			}
			else if (arr[y][x] == 'S' && (arr[yy][xx] == 'D' || arr[yy][xx] == '.')) {
				arr[yy][xx] = 'S';
				q.push({{yy, xx}, t+1});
			}
		}
	}
	cout << "KAKTUS\n";
	return 0;	
}
