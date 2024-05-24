#include <bits/stdc++.h>
using namespace std;

vector<int> g[10007], dp(10007, 1e9);

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int k, n, m, a, b;
  cin >> k >> n >> m;
  while (m--) {
    cin >> a >> b;
    g[a].push_back(b);
  }
  dp[1] = 0;
  for (int i = 1; i <= n; i++) {
    for (auto j : g[i]) {
      dp[j] = min(dp[j], dp[i]+1);
    }
  }
  for (int i = n; i >= 1; i--) {
    if (dp[i] <= k) {
      cout << i;
      break;
    }
  }
  return 0;
}