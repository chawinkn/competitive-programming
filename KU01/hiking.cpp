#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, s, h;
  cin >> n >> s;
  int mn=s, mx=s, a, b;
  for (int i = 0; i < n; i++) {
    cin >> h;
    a = h*10/3;
    b = h*10/4;
    if (h%3 == 0 && h%4 == 0) {
      mn -= a;
      mx -= b;
    }
    else if (h%3 == 0) {
      mn -= a;
      mx -= a;
    }
    else if (h%4 == 0) {
      mn -= b;
      mx -= b;
    }
  }
  cout << mn << " " << mx;
  return 0;
}