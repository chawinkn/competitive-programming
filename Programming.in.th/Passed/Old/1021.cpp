#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  priority_queue<int> pq;
  int n, i;
  char t;
  cin >> n;
  while (n--) {
    cin >> t;
    if (t == 'P') {
      cin >> i;
      pq.push(i);
    }
    else if (t == 'Q') {
      if (!pq.empty()) {
        cout << pq.top() << "\n";
        pq.pop();
      }
      else {
        cout << -1 << "\n";
      }
    }
  }
  return 0;
}