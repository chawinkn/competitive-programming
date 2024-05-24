#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

pair<int,int> dp[159]; // child, adult

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	dp[1] = {0, n};
	for (int i = 2; i <= m; i++) {
        int c=dp[i-1].f+dp[i-1].s/2;
        int a=(i >= 3 ? dp[i-3].f : 0) + dp[i-1].s/2;
        dp[i] = {c, a};
    }
	cout << dp[m].f+dp[m].s;
	return 0;
}
