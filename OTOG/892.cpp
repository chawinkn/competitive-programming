#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll minPenguinValue(int N, int M, vector<int> A) {
	// vector<vector<ll>> F(N+1, vector<ll>(N+1));
	vector<ll> qs(N+1);
	for (int i = 1; i <= N; i++) qs[i] = qs[i-1]+A[i-1]*A[i-1]; // A[1]^2+A[2]^2+...+A[i]^2
	// for (int l = 1; l <= N; l++) {
	// 	ll sum=0;
	// 	for (int r = l; r <= N; r++) {
	// 		// for (int i = l; i <= r; i++) {
	// 		// 	for (int j = i; j <= r; j++) {
	// 		// 		F[l][r] += A[i-1]*A[j-1];
	// 		// 	}
	// 		// }
	// 		// F[l][r] #
	// 		F[l][r] = F[l][r-1]+sum*A[r-1]; // Previous + Multiply A[r-1] with every previous element
	// 		sum += A[r-1]; // Add element
	// 		// F[l][r]+qs[r]-qs[l-1] #
	// 	}
	// }
	vector<vector<ll>> dp(2, vector<ll>(N+1, 1e18));
	dp[0][0] = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) { // left
			ll sum=0, F=0;
			for (int k = j; k <= N; k++) { // right
				F = F+sum*A[k-1];
				sum += A[k-1];
				dp[i%2][k] = min(dp[i%2][k], dp[(i-1)%2][j-1]+F+qs[k]-qs[j-1]);
			}
		}
	}
    return dp[M%2][N];
}

// int main() {
// 	cout << minPenguinValue(5, 3, {1,2,3,4,5});
// 	return 0;
// }