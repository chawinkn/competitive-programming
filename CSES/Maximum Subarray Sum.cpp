#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	ll x;
	cin >> n >> x;
	ll sum=x, ans=x;
	for (int i = 1; i < n; i++) {
		cin >> x;
		sum = max(sum+x, x);
		ans = max(ans, sum);
	}         
	cout << ans;
	return 0;
}