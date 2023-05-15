#include <bits/stdc++.h>
using namespace std;

long long int t[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	long long int n, sum, l, r, mid;
	cin >> m >> n;
	for (int i = 0; i < m; i++) cin >> t[i];
	l = 1;
	r = 1e6*n;	
	while (l <= r) {
		mid = (l+r)/2;
		sum = 0;
		for (int i = 0; i < m; i++) sum += mid/t[i];
		if (sum >= n) r = mid-1;
		else l = mid+1;
	}
	cout << l;
	return 0;
}
