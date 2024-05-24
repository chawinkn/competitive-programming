#include <bits/stdc++.h>
using namespace std;

bool dp[100009];
int a[109];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			if (i >= a[j] && !dp[i-a[j]]) dp[i] = true;
		}
	}
	cout << (dp[k] ? "First" : "Second");
	return 0;
}