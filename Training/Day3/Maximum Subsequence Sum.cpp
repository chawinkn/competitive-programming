#include <bits/stdc++.h>
using namespace std;

// DP, Greedy

int a[200009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	int sum=0, mx=-2e9, l=1, r=1, L=n, R=n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		if (sum > mx) {
			mx = sum;
			r = i, L = l, R = r;
		}
		if (sum < 0) {
			sum = 0;
			l = r = i+1;
		}
	}
	cout << L << " " << R << "\n" << mx;
	return 0;
}