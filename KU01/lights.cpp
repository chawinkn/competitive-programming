#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, arr[1001], ans=0, dis=0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr+n);
  for (int i = 0; i < n; i++) {
    dis += arr[i];
    ans += dis;
  }
  cout << 2*ans; 
  return 0;
}