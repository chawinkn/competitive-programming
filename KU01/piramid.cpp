#include <bits/stdc++.h>
using namespace std;

int main() {
  int l, n, k, cnt=0;
  cin >> l >> n;
  for (int i = 1; i <= l; i++) {
    k = i*i;
    if (n >= k) {
      n -= k;
      cnt++;
    }
    else break;
  }
  cout << l-cnt;
  return 0;
}