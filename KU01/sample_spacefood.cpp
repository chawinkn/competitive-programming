#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, k, a, food=0, alive=1, ans=0;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a;
    food += a;
    if (food >= m) {
      if (food >= k) food -= k;
      else {
        food = 0;
        ans++;
      }
    }
    else alive = 0;
  }
  if (alive) cout << ans;
  else cout << -1;
  return 0;
}