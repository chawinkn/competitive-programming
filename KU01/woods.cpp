#include <bits/stdc++.h>
using namespace std;

int arr[9][100001], dp[100001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n, w, l, k, pos, ans=-1;
  cin >> n >> w >> l;
  for (int i = 1; i <= n; i++) {
    cin >> k;
    for (int j = 1; j <= k; j++) {
      cin >> pos;
      for (int x = pos-l; x <= pos+l; x++) {
        if (x >= 1 && x <= w && !arr[i][x]) {
          arr[i][x] = 1;
          dp[x]++;
          ans = max(ans, dp[x]);
        }
      }
    }
  }
  if (ans == n) cout << 1;
  else cout << 0;
  return 0;
}