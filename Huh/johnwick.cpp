#include <bits/stdc++.h>
using namespace std;

bool dp[2][100009];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int b, t, n, c;
    cin >> b >> t;
    dp[0][0] = true;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        while (n--) {
            cin >> c;
            for (int j = c; j <= b; j++) 
                dp[i%2][j] |= dp[(i-1)%2][j-c];
        }
    }
    for (int i = b; i >= 1; i--) {
        if (dp[t%2][i]) {
            cout << i;
            return 0;    
        }
    }
    cout << "no solution";
    return 0;
}

// 35 4
// 3 13 4 5
// 2 3 15
// 4 10 7 8 2
// 1 2

// 32