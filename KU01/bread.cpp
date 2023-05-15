#include <bits/stdc++.h>
using namespace std;

int wx[1001], wy[1001];

int main() {
  int w, h, m, n, prev, num;
  cin >> w >> h >> m >> n;
  prev = 0;
  for (int i = 0; i < m; i++) {
    cin >> num;
    wx[i] = num-prev;
    prev = num;
  }
  wx[m] = w-prev;
  prev = 0;
  for (int i = 0; i < n; i++) {
    cin >> num;
    wy[i] = num-prev;
    prev = num;
  }
  wy[n] = h-prev;

  sort(wx, wx+m+1);
  sort(wy, wy+n+1);
  cout << wx[m]*wy[n] << " " << max(wx[m]*wy[n-1], wx[m-1]*wy[n]);
  return 0;
}