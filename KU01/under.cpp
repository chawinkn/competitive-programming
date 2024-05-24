#include <bits/stdc++.h>
using namespace std;

int dp[301];

int main() {
  int l, n, a, b, ans=-1;
  cin >> l >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    dp[a]++;
    dp[b]--;
  }
  for (int i = 1; i <= l; i++) {
    dp[i] += dp[i-1];
    ans = max(ans, dp[i]);
  }
  cout << ans;
  return 0;
}