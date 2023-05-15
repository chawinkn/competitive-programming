#include <bits/stdc++.h>
using namespace std;

int arr[13];
bool dp[1000003];

int main() {
    int n, m;
    while (cin >> n) {
        cin >> m;
        for (int i = 0; i < m; i++) cin >> arr[i];
        dp[0] = false;
        for (int i = 1; i <= n; i++) {
            dp[i] = false;
            for (int j = 0; j < m; j++) {
                if (i-arr[j] >= 0 && !dp[i-arr[j]]) dp[i] = true;
            }
        }
        if (dp[n]) cout << "Stan wins\n";
        else cout << "Ollie wins\n";
    }
    return 0;
}