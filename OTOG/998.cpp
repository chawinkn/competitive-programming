#include <bits/stdc++.h>
using namespace std;

int a[2009], dp[2009];
bool visited[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		int mx=0, unq=0;
		for (int j = i-1; j >= 0; j--) {
			mx = max(mx, a[j+1]);
			if (!visited[a[j+1]]) {
				visited[a[j+1]] = true;
				unq++;
			}
			dp[i] = max(dp[i], dp[j]+mx*unq);
		}
	}
	cout << dp[n];
	return 0;
}