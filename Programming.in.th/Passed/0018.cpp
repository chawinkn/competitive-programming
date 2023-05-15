#include <bits/stdc++.h>
using namespace std;

int p[1001];

int main() {
	int n, k, ans;
	cin >> n >> k;
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j+=i) {
			if (!p[j]) {
				p[j] = 1;
				k--;
				if (k == 0) ans = j;
			}
		}	
	}
	cout << ans;
	return 0;
}
