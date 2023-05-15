#include <bits/stdc++.h>
using namespace std;

long long int qs[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q, p, c;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> p;	
		qs[i] = p+qs[i-1];
	}
	for (int i = n-1; i >= 1; i--) qs[i] = min(qs[i], qs[i+1]);		
	for (int i = 0; i < q; i++) {
		cin >> c;
		cout << upper_bound(qs+1, qs+n+1, c)-qs-1 << "\n";
	}
//	1  2  3  4  5
//	10 30 20 50 110
//     ** 30 must be <= 20 so we change 30 to 20 (min(30, 20))
//  10 20 20 50 110
	return 0;
}

