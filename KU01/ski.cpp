#include <bits/stdc++.h>
using namespace std;

int main() {
  int l, m, n, s, x, out;
  cin >> l >> m >> n;
  for (int i = 0; i < n; i++) {
    out = 0;
    s = l;
    for (int j = 0; j < m; j++) {
      cin >> x;
      if (x == 1) s++;
      else s--;
      if (s < 0 || s > 2*l) out = 1;
    }
    if (!out) cout << 1 << "\n";
    else cout << 0 << "\n";
  }
  return 0;
}