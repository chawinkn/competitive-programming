#include <bits/stdc++.h>
using namespace std;

int cnt[301];

int main() {
  int n, k, num, m=100001;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> num;
    cnt[num]++;
  }
  for (int i = 1; i <= k; i++) m = min(m, cnt[i]);
  cout << n-k*m;
  return 0;
}

/**
cnt
1 2 -> 1 -> 0
2 3 -> 2 -> 1
3 5 -> 4 -> 3
ans = 0+1+3 = 4

cnt
1 2   m -> 2
2 3   m =  2 
3 5   m =  2
ans = 10 - 2*3 = 4
**/