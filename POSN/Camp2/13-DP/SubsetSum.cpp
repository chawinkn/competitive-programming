#include <bits/stdc++.h>
using namespace std;

int arr[13];

int main() {
    int n, sum;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    cin >> sum;
    int dp[n+1][sum+1]={0};
    for (int i = 1; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= sum; i++) {
        if (arr[1] == i) dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]];
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= sum; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    if (dp[n][sum]) cout << "YES";
    else cout << "NO";
    return 0;
}