#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll arr[2009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < 2*n; i++) cin >> arr[i];
	sort(arr, arr+2*n);
	ll ans=0;
	for (int i = 0; i < n; i++) ans += arr[i]*arr[2*n-i-1];
	cout << ans;
	return 0;
}
