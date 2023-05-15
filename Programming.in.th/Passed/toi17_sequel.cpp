#include <bits/stdc++.h>
using namespace std;

long long int arr[100003], qs[100003], sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q, l, m, r;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		qs[i] = arr[i]+qs[i-1];		
	}
	for (int i = 0; i < q; i++) {
		cin >> l >> m >> r;
		if (m == 1) {
			sum = qs[r]-qs[l-1];	
		}
		else {
			sum = 0;
			for (int j = l; j <= r; j+=m) sum += arr[j];
		}
		cout << sum << " ";
	}
	return 0;
}
