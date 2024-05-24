#include <bits/stdc++.h>
using namespace std;
//1 3/4 1/2 1/4 1/8
//8 6  4    2    1
int dp[3009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int w, h, n, x, a;
	cin >> w >> h >> n;
	while (n--) {
		cin >> x >> a;
		dp[x]++, dp[x+a]--;
	}
	int all=0, half=0;
	for (int i = 0; i < w; i++) {
		dp[i] += dp[i-1];
		if (dp[i] == 0) all++;
		if (dp[i] == 1) half++;
	}
	cout << all*h << " " << half*h << "\n";
	return 0;
}