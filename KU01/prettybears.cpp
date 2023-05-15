#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b, ans=0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a >= 100 && a <= 750 && b >= 80) ans++;
  }
  cout << ans;
  return 0;
}