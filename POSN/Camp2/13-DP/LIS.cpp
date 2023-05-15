#include <bits/stdc++.h>
using namespace std;

int arr[10003], dp[10003];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) { // ตัวจบ
        dp[i] = 1;
        for (int j = 0; j < i; j++) { // Sequence ก่อน
            if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j]+1); // เก่า กับ ต่อตัว arr[i] เพิ่ม
        }
    }
    int ans=0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans;
    return 0;
}