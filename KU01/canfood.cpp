#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b, cnt=0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a <= 400 && b >= 150 && b <= 200) cnt++;
  }
  cout << cnt;
  return 0;
}