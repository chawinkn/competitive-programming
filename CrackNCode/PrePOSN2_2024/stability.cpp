#include <bits/stdc++.h>
using namespace std;

#define ll long long

// 7/100 lol

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n, m, k, h;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> h;
		}
	}
	cout << max(h*n*m, h+k);
	return 0;
}