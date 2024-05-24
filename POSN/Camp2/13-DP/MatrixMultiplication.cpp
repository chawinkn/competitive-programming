#include <bits/stdc++.h>
using namespace std;

int arr[103], dp[103][103];

int main() {
    int n;
    cin >> n;
    n++;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 1; i < n; i++) dp[i][i] = 0;
    for (int l = 2; l < n; l++) {
        for (int i = 1; i <= n-l; i++) {
            int j=i+l-1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+(arr[i-1]*arr[k]*arr[j]));
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << "Minimum number of multiplications is " << dp[1][n-1];
    return 0;
}