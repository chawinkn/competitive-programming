#include <bits/stdc++.h>
using namespace std;

int arr[101][101];

int main() {
  int l, w, n, a, b, c, d, cnt, ans=0;
  cin >> l >> w >> n;
  for (int k = 0; k < n; k++) {
    cin >> a >> b >> c >> d;
    for (int i = b; i < d; i++) {
      for (int j = a; j < c; j++) arr[i][j] = 1;
    }
  }
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < l; j++) {
      cnt=0;
      for (int y = i; y < i+3; y++) {
        for (int x = j; x < j+3; x++) {
          if (y >= 0 && y < w && x >= 0 && x < l && !arr[y][x]) cnt++;
        }
      }
      if (cnt == 9) ans++;
    }
  }
  cout << ans;
}
