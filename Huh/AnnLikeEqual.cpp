#include <bits/stdc++.h>
using namespace std;

#define ll long long

map<int,int> cnt;

int main() {
	int n, a, mx=0;
	cin >> n;
	ll sum=0;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		sum += a;
		cnt[a]++;
		mx = max(mx, cnt[a]);
	}
	if (sum%n == 0) cout << n;
	else cout << mx;
	return 0;
}