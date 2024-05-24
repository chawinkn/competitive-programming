#include <bits/stdc++.h>
using namespace std;

int dp[100001], h[100001];

int main() {
  int n, l, a;
  cin >> n >> l;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    dp[i] = max(dp[i-1], h[i]);
  }
  for (int i = 0; i < l; i++) {
    cin >> a;
    if (h[a] <= dp[a-1]) {
      cout << dp[a-1]-h[a]+1 << "\n";
    }
    else {
      cout << 0 << "\n";
    }
  }
  return 0;
}