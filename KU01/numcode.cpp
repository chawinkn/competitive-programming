#include <bits/stdc++.h>
using namespace std;

int x[53], y[53], z[53];

int main() {
  int n, t;
  cin >> n >> t;
  if (t == 1) {
    for (int i = 1; i <= n; i++) cin >> y[i];
  }
  else if (t == 2) {
    // decode step 2
    for (int i = 1; i <= n; i++) {
      cin >> z[i];
      if (i == 1) y[1] = z[1];
      else {
        y[i] = z[i]-2*y[i-1];
        if (y[i] != y[i-1]+1) y[i] = y[i-1]-1;
      }
    }
  }
  // decode step 1
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      if (y[1] == n+1) x[1] = 1;
      else if (y[1] == n-1) x[1] = 0;
    }
    else {
      if (y[i] == y[i-1]+1) x[i] = 1;
      else if (y[i] == y[i-1]-1) x[i] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << x[i] << "\n";
  }
  return 0;
}