#include <bits/stdc++.h>
using namespace std;

int a[200009];
unordered_map<int,int> want, now;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) {
		int b;
		cin >> b;
		want[b]++;
	}
	int ans=0, cnt=0;
	for (int i = 1; i <= m; i++) now[a[i]]++;
	for (auto j : now) cnt += min(j.second, want[j.first]);
	ans += (cnt >= k);
	for (int i = m+1; i <= n; i++) {
		cnt -= min(now[a[i-m]], want[a[i-m]]);
		if (now[a[i-m]] > 0) {
			now[a[i-m]]--;
			cnt += min(now[a[i-m]], want[a[i-m]]);
		}
		cnt -= min(now[a[i]], want[a[i]]);
		now[a[i]]++;
		cnt += min(now[a[i]], want[a[i]]);
		
		ans += (cnt >= k);
	}
	cout << ans;
	return 0;
}