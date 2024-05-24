#include <bits/stdc++.h>
using namespace std;

int main() {
  int w, l, arr[51][51], ans=0;
  cin >> w >> l;
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < l; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i <= w-5; i++) {
    for (int j = 0; j <= l-5; j++) {
      int v[10]={0}, cnt=0;
      for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
          if (!v[arr[i+r][j+c]]) {
            v[arr[i+r][j+c]] = 1;
            cnt++;
          }
        }
      }
      if (cnt >= 5) ans++;
    }
  }
  cout << ans;
  return 0;
}