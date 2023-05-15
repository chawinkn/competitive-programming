#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

char arr[51][51];
int dist1[51][51], dist2[51][51], dx[]={0,1,0,-1}, dy[]={-1,0,1,0};
pair<int,int> s, e;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'D') e = {i, j};
			else if (arr[i][j] == 'S') s = {i, j};
		}
	}
	int visited[51][51]={0};
	queue<pair<int,int>> q;
	q.push(s);
	while (!q.empty()) {
		int y=q.front().f, x=q.front().s;
		q.pop();
		if (visited[y][x]) continue;
		visited[y][x] = 1;
		for (int i = 0; i < 4; i++) {
			int yy=y+dy[i], xx=x+dx[i];
			if (yy >= 0 && yy < r && xx >= 0 && xx < c && ) {
				
			}
		}
	}
	return 0;
}
