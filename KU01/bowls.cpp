#include <bits/stdc++.h>
using namespace std;

int cnt[301];

int main() {
  int n, num, ans=0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    cnt[num]++;
    ans = max(ans, cnt[num]);
  }
  cout << ans;
  return 0;
}