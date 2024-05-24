//#include <bits/stdc++.h>
//using namespace std;
// 
//int dp[1000009];
// 
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		dp[i] = 1e6;
//		int num=i;
//		while (num > 0) {
//			dp[i] = min(dp[i], dp[i-num%10]+1);
//			num /= 10;
//		}
//	}
//	cout << dp[n];
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;
int dp[1000009];

int solve(int n) {
    if (n == 0) return 0;
    if (n < 0) return INF;
    if (dp[n] != -1) return dp[n];
    
    int min_steps = INF;
    int num = n;
    while (num > 0) {
        min_steps = min(min_steps, solve(n - num % 10) + 1);
        num /= 10;
    }
    
    return dp[n] = min_steps;
}

int main() {
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << solve(n);
    return 0;
}

