#include <bits/stdc++.h>
using namespace std;

#define ll long long

int a[200009];
map<ll,int> mp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	ll x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	int l=0;
	ll sum=0, ans=0;
	mp[0] = 1;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		ans += mp[sum-x];
		mp[sum]++;
	}
	cout << ans;
	return 0;
}