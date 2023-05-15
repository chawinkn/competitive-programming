#include <bits/stdc++.h>
using namespace std;

char board[103][103];
int dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};

int main() {
    int n, r, c;
    char fill, color;
    cin >> n >> fill >> r >> c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> board[i][j];
    }
    queue<pair<int,int>> q;
    q.push({r, c});
    color = board[r][c];
    while (!q.empty()) {
        int y=q.front().first, x=q.front().second;
        q.pop();
        board[y][x] = fill;
        for (int i = 0; i < 4; i++) {
            int yy=y+dy[i], xx=x+dx[i];
            if (yy < 0 || yy >= n || xx < 0 || xx >= n) continue;
            if (board[yy][xx] == color) q.push({yy, xx});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << board[i][j];
        cout << "\n";
    }
}