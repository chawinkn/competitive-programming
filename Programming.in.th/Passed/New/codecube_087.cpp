#include <bits/stdc++.h>
using namespace std;

int cnt[1000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, num;
	long long ans=0;
	cin >> n >> m;
	while (n--) {
		cin >> num;
		ans += cnt[max(m-num, 0)];
		cnt[num]++;
	}
	cout << ans;
	return 0;
}
