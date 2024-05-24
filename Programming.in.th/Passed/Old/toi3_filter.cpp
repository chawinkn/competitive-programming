#include <bits/stdc++.h>
using namespace std;

int dp[3001];

int main() {
	int w, h, n, x, a, all=0, half=0;
	cin >> w >> h >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> a;
		for (int j = x; j < x+a; j++) dp[j]++;
	}
	for (int i = 0; i < w; i++) {
		if (dp[i] == 0) all += h;
		else if (dp[i] == 1) half += h;
	}
	cout << all << " " << half;
	return 0;
}
