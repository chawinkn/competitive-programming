#include <bits/stdc++.h>
using namespace std;

int s[13], b[13];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, ans=1e9;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i] >> b[i];
	// Slower than recursive ::skull::
	for (int i = 1; i < (1<<n); i++) {
		int ss=1, bb=0;
		for (int j = 0; j < n; j++) {
			if (i & (1<<j)) {
				ss *= s[j];
				bb += b[j];
			}
		}
		ans = min(ans, abs(ss-bb));
	}
	cout << ans;
	return 0;
}
