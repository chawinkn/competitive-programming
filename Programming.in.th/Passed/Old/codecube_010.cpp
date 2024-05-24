#include <bits/stdc++.h>
using namespace std;

int bombed[500001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, b, cnt=0;
	cin >> n >> b;
	for (int i = 2; i <= n; i++) {
		if (!bombed[i]) {
			for (int j = i; j <= n; j+=i) {
				bombed[j] = 1;
			}
			cnt++;
		}
	}
	if (cnt > b) cout << cnt-b;
	else cout << 0;
	return 0;
}
