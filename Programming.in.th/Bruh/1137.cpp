#include <bits/stdc++.h>
using namespace std;

long long arr[1000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	long long ans=0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 1; i < n-1; i++) ans += arr[i]+arr[0];
	ans += arr[n-1];
	cout << ans;
	return 0;
}
