#include <bits/stdc++.h>
using namespace std;

#define ll long long

int a[200009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	ll x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	int l=0;
	ll sum=0, ans=0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		while (sum > x) {
			sum -= a[l];
			l++;
		}
		if (sum == x) ans++;
	}
	cout << ans;
	return 0;
}