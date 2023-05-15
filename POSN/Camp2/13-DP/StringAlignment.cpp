#include <bits/stdc++.h>
using namespace std;

int dp[5003][5003];
string a=" ", b=" ", ina, inb;

int score(char a, char b) {
    if (a == b) return 2;
    return -1;
}

int main() {
    cin >> ina >> inb;
    a += ina;
    b += inb;
    int n=a.length()-1, m=b.length()-1;
    for (int i = 1; i <= n; i++) dp[i][0] = i*score(a[i], '_');
    for (int i = 1; i <= m; i++) dp[0][i] = i*score('_', b[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i-1][j-1]+score(a[i], b[j]), max(dp[i-1][j]+score(a[i], '_'), dp[i][j-1]+score('_', b[j])));
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << "Alignment score: " << dp[n][m];
    return 0;
}