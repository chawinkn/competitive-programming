#include <bits/stdc++.h>
using namespace std;

bool p[5009], visited[709][5009][4];
int dp[709][5009][4];
vector<int> prime;

int solve(int i, int sum, int k) {
	if (sum < 0 || i >= prime.size() || k > 3) return 0;
	if (sum == 0) return 1;
	if (visited[i][sum][k]) return dp[i][sum][k];
	visited[i][sum][k] = true;	
	dp[i][sum][k] = solve(i+1, sum, k) + solve(i, sum-prime[i], k+1);
	return dp[i][sum][k];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	memset(p, true, sizeof(p));
	p[0] = p[1] = false;
	for (int i = 2; i <= 5000; i++) {
		if (!p[i]) continue;
		prime.push_back(i);
		for (int j = 2*i; j <= 5000; j+=i) p[j] = false;
	}
	while (n--) {
		int m;
		cin >> m;
		cout << solve(0, m, 0)-(!p[m]) << "\n";
	}
	return 0;
}

//5
//3
//9
//17
//21
//33