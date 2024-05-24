#include <bits/stdc++.h>
using namespace std;

int n, a, l;
string t;
vector<vector<int>> dp(109, vector<int>(109, -1));
vector<string> bags[109];

int solve(int i, int j) {
    if (j >= l) return 0;
    if (i > n) return 1e9;
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j] = solve(i+1, j);
    for (auto s : bags[i]) {
        int k = s.length();
        if (j+k <= l && t.substr(j, k) == s) 
			dp[i][j] = min(dp[i][j], solve(i+1, j+k)+1);
    }
    return dp[i][j];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> t >> n;
    l = t.length();
    for (int i = 1; i <= n; i++) {
        cin >> a;
        for (int j = 1; j <= a; j++) {
            cin >> s;
            bags[i].push_back(s);    
        }
    }
    solve(1, 0);
    cout << (dp[1][0] == 1e9 ? -1 : dp[1][0]);
    return 0;
}