#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k, ans=0;
	cin >> k >> n;
	for (int i = 0; i < n; i++) ans += __builtin_popcount(i^(i+1));
	cout << ans;
	return 0;
}
