#include <bits/stdc++.h>
using namespace std;

#define M 20

double dp[(1<<M)+3][2], arr[23][23];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			arr[i][j] /= 100;
		}
	}
	
	for (int i = 0; i < n; i++) dp[(1<<i)][0] = arr[0][i];
	
	for (int i = 1; i < n; i++) {
		int curr=i%2, prev=(i-1)%2;
		for (int j = 0; j < (1<<n); j++) {
			bitset<32> b(j);
			if (b.count() != i+1) continue;
			
			dp[j][curr] = dp[j][prev];
			for (int k = 0; k < n; k++) {
				if (!(j & (1<<k))) continue;
				dp[j][curr] = max(dp[j][curr], dp[j^(1<<k)][prev]*arr[i][k]);
			}
		}
	}
	printf("%.12lf", dp[(1<<n)-1][(n+1)%2]*100);
	return 0;
}
