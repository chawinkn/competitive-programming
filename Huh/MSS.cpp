#include <bits/stdc++.h>
using namespace std;

int arr[100009];

int solve(int l, int r) {
	if (l == r) return arr[l];
	int m=(l+r)/2, ml=-1e9, mr=-1e9;
	int sum=0;
	for (int i = m; i >= l; i--) {
		sum += arr[i];
		ml = max(ml, sum);
	}
	sum = 0;
	for (int i = m+1; i <= r; i++) {
		sum += arr[i];
		mr = max(mr, sum);
	}
	return max({solve(l, m), solve(m+1, r), ml+mr});
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	cout << solve(1, n);
	return 0;
}