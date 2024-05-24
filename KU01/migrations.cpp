#include <bits/stdc++.h>
using namespace std;

int h, w, n, a, b, c, d, l, visited[31][31], up, down, founded;
char arr[31][31];

void bfs(int y, int x, int v[31][31]) {
    if (y == c && x == d) founded = 1;
    if (!founded && arr[y][x] != '#') {
      v[y][x] = 1;
      // U
      if (y-1 >= 1 && y-1 >= up && arr[y-1][x] != '#' && !v[y-1][x]) bfs(y-1, x, v);
      // R
      if (x+1 <= w && arr[y][x+1] != '#' && !v[y][x+1]) bfs(y, x+1, v);
      // D
      if (y+1 <= h && y+1 <= down && arr[y+1][x] != '#' && !v[y+1][x]) bfs(y+1, x, v);
      // L
      if (x-1 >= 1 && arr[y][x-1] != '#' && !v[y][x-1]) bfs(y, x-1, v);
    }
}

int main() {
  cin >> h >> w >> n;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c >> d >> l;
    // int visited[31][31]={0};
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) visited[i][j] = 0;
    }
    founded = 0;
    up = a-l;
    down = a+l;
    bfs(a, b, visited);
    cout << founded << "\n";
  }
  return 0;
}