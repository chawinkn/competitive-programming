#include <bits/stdc++.h>
using namespace std;

int d[1000009], last[1000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, num, ans=0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> d[i];
	for (int j = 1; j <= m; j++) {
		cin >> num;
		if (j-last[num] >= d[num]) {
			ans++;
			last[num] = j;
		}
	}
	cout << ans;
	return 0;
}
