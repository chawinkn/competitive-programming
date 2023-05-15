#include <bits/stdc++.h>
using namespace std;

int cnt[10009], ans[100009], mx[100009], k[100009];

int main() {
	int n, m, a, l, s, j=1;
	cin >> n >> m;
	while (n--) {
		cin >> a >> l >> s;
		cnt[l]++;
		j = max(j, cnt[l]);
		if (s > mx[cnt[l]]) {
			ans[cnt[l]] = a;
			mx[cnt[l]] = s;
			k[cnt[l]] = l;
		}
		else if (s == mx[cnt[l]] && l < k[cnt[l]]) {
			ans[cnt[l]] = a;
			k[cnt[l]] = l;
		}
	}
	for (int i = 1; i <= j; i++) cout << ans[i] << "\n";
	return 0;
}
