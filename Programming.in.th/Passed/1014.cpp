#include <bits/stdc++.h>
using namespace std;

int dp[3001];

int main() {
	int w, h, n, a, x, all=0, half=0;
	cin >> w >> h >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> a;
		dp[x]++;
		dp[x+a]--;
	}
	for (int i = 1; i < w; i++) dp[i] += dp[i-1];	
	for (int i = 0; i < w; i++) {
		if (dp[i] == 0) all += h;
		else if (dp[i] == 1) half += h;
	}
	cout << all << " " << half;
	return 0;
}
