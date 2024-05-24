#include <bits/stdc++.h>
using namespace std;

int n, cnt, ans=0, x[1007], visited[1007];

void solve() {
	int i=0, j=1, max=-1, maxi, maxj;
	while (i < n && visited[i]) i++;
	while (j < n && visited[j]) j++;

	while (i < n && j < n) {
		if (abs(x[i]-x[j]) > max) {
			max = abs(x[i]-x[j]);
			maxi = i;
			maxj = j;
		}
		i = j;
		j++;
		while (j < n && visited[j]) j++;
	}

	visited[maxi] = 1;
	visited[maxj] = 1;
	ans += max;
	cnt -= 2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	cnt = n;
	for (int i = 0; i < n; i++) cin >> x[i];
	while (cnt > 1) solve();
	cout << ans;
	return 0;
}