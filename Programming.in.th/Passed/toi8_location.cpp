#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main() {
  int m, n, k, num, ans=0;
  cin >> m >> n >> k;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> num;
      dp[i][j] = dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+num;
    }
  }
  for (int i = k; i <= m; i++) {
    for (int j = k; j <= n; j++) {
      ans = max(ans, dp[i][j]-dp[i-k][j]-dp[i][j-k]+dp[i-k][j-k]);
    }
  }
  cout << ans;
  return 0;
}