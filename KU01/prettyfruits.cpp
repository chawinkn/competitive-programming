#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, ans=0;
  float w, l;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> l >> w;
    if (w <= 0.75*l) ans += 5;
    else ans += 3;
  }
  cout << ans;
  return 0;
}