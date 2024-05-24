#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g(10001);
int visited[10001], dist[10001];

int main() {
  int k, n, m, a, b;
  cin >> k >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    g[a].push_back(b);
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
  dist[1] = 0;
  q.push(1);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto i : g[v]) {
      if (!visited[i]) {
        visited[i] = 1;
        dist[i] = min(dist[i], dist[v]+1);
        q.push(i);
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    if (dist[i] <= k) {
      cout << i << "\n";
      break;
    }
  }
  return 0;
}
