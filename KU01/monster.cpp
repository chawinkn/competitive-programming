#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, h, a, m=0;
  cin >> n >> h;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a > m && a <= h) m = a;
  }
  cout << m;
  return 0;
}