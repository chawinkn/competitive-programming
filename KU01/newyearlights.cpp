#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> target(100001);
vector<vector<int>> graph(100001);
int visited[100001], cnt=0;

void dfs(int x) {
  if (visited[x]) return;
  visited[x] = 1;
  cnt++;
  for (auto u : graph[x]) {
    for (auto v : target[u]) {
      int check=1;
      for (auto w : v) {
        if (!visited[w]) {
          check=0;
          break;
        }
      }
      if (check) {
        dfs(u);
        break;
      }
    }
  }
}

int main() {
  int n, m, s, k, t;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    vector<int> temp;
    cin >> k;
    for (int j = 0; j < k; j++) {
      cin >> s;
      temp.push_back(s);
    }
    cin >> t;
    target[t].push_back(temp);
    for (auto u : temp) graph[u].push_back(t);
  }
  dfs(1);
  cout << cnt;
}
