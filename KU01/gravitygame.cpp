#include <bits/stdc++.h>
using namespace std;

int h[101];

int main() {
  int n, k;
  char c;
  cin >> n;
  for (int i = 0; i < n; i++) {
    k = 0;
    for (int j = 0; j < n; j++) {
      cin >> c;
      if (c == '#') {
        h[k]++;
        k++;
      }
    }
  }
  for (int i = n; i > 0; i--) {
    for (int j = 0; j < n; j++) {
      if (i <= h[j]) cout << "#";
      else cout << ".";
    }
    cout << "\n";
  }
  return 0;
}

/**
k = rock index
.....
.0.1.
.012.
...01
0....
h 4 3 1 0 0 (ans)
**/