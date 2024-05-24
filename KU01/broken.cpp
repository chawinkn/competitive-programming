#include <bits/stdc++.h>
using namespace std;

int n, visited[31][31], cnt=0;
char arr[31][31];

void bfs(int y, int x) {
  if (!visited[y][x] && arr[y][x] == '.') {
    if (x >= 0 && x < n && y >= 0 && y < n) {
      visited[y][x] = 1;
      cnt++;
      // Up
      bfs(y-1, x);
      // Down
      bfs(y, x-1);
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  bfs(n-1, n-1);
  cout << cnt;
  return 0;
}