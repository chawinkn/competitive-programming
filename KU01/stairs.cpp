#include <bits/stdc++.h>
using namespace std;

int dpg[100001], dph[100001], cnt[100001];

int main() {
  // Use this if you dont wanna get T lol (my algorithm not fast enough)
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  
  int n, q, s, e, l, h, num, prev;
  cin >> n;
  cin >> prev;
  for (int i = 2; i <= n; i++) {
    cin >> num;
    s = min(num, prev);
    e = max(num, prev);
    prev = num;
    for (int j = s+1; j < e; j++) cnt[j]++;
  }
  for (int i = 1; i <= 100001; i++) {
    dpg[i] = dpg[i-1];
    dph[i] = dph[i-1];
    if (i%2 == 0) dpg[i] += cnt[i];
    else dph[i] += cnt[i];
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> l >> h;
    cout << dpg[h]-dpg[l-1] << " " << dph[h]-dph[l-1] << "\n";
  }
  return 0;
}