#include <bits/stdc++.h>
using namespace std;

double arr[100001], m=1000000001;

int main() {
  int n, k, ans;
  cin >> n >> k;
  ans = n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    m = min(m, arr[i]);
  }
  for (int i = 0; i < n; i++) {
    if (arr[i]-m >= arr[i]/k) ans--;
  }
  cout << ans;
  return 0;
}