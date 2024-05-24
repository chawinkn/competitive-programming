#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

// 100/100 here but 90/100 in toi8_maze ????

bool arr[159][159];
int dy[]={0,-1,0,1}, dx[]={-1,0,1,0};
vector<vector<int>> dist1(159, vector<int>(159, 2e9)), dist2(159, vector<int>(159, 2e9));
queue<pair<int,int>> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m, n, sy, sx, ey, ex;
    cin >> m >> n >> sy >> sx >> ey >> ex;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) cin >> arr[i][j];
    }
    dist1[sy][sx] = 1;
    q.push({sy, sx});
    while (!q.empty()) {
        int y=q.front().f, x=q.front().s; q.pop();
        for (int i = 0; i < 4; i++) {
            int yy=y+dy[i], xx=x+dx[i];
            if (yy < 1 || yy > m || xx < 1 || xx > n) continue;
            if (!arr[yy][xx]) {
            	dist1[yy][xx] = min(dist1[yy][xx], dist1[y][x]);
            	continue;
			}
			if (dist1[y][x]+1 < dist1[yy][xx]) {
                dist1[yy][xx] = dist1[y][x]+1;
                q.push({yy, xx});
            }
        }
    }
    dist2[ey][ex] = 1;
    q.push({ey, ex});
    while (!q.empty()) {
        int y=q.front().f, x=q.front().s; q.pop();
        for (int i = 0; i < 4; i++) {
            int yy=y+dy[i], xx=x+dx[i];
            if (yy < 1 || yy > m || xx < 1 || xx > n) continue;
            if (!arr[yy][xx]) {
            	dist2[yy][xx] = min(dist2[yy][xx], dist2[y][x]);
            	continue;
			}
            if (dist2[y][x]+1 < dist2[yy][xx]) {
                dist2[yy][xx] = dist2[y][x]+1;
                q.push({yy, xx});
            }
        }
    }
	int cnt=0, ans=2e9;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] || dist1[i][j] == 2e9 || dist2[i][j] == 2e9) continue;
			ans = min(ans, dist1[i][j]+dist2[i][j]+1);
			cnt++;
		}
	}
	cout << cnt << "\n" << ans;
    return 0;
}
