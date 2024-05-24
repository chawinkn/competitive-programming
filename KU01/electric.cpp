#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, l, ans=1000001, d;
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    int arr[101];
    arr[0] = 0;
    d = 0;
    for (int j = 1; j <= l; j++) {
      cin >> arr[j];
      d = max(d, arr[j]-arr[j-1]);
    }
    ans = min(ans, d);
  }
  cout << ans;
  return 0;
}