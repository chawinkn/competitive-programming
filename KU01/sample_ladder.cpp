#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int main() {
  int n, m, d, p=0, out=0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> d;
    p += d;
    if (p >= 0 && p <= n) p += arr[p];
  }
  if (p <= 0) cout << 0;
  else if (p >= n) cout << n;
  else cout << p;
  return 0;
}