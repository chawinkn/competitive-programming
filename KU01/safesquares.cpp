#include <bits/stdc++.h>
using namespace std;

unordered_set<int> x, y;

int main() {
  int n, m, k, a, b;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    cin >> a >> b;
    x.insert(a);
    y.insert(b);
  }
  cout << ((n-x.size())%25621*(m-y.size())%25621)%25621;
  return 0;
}