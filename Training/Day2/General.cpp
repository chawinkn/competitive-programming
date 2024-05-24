#include <bits/stdc++.h>
using namespace std;

// DSU

int p[100009], cnt[100009];

int find(int u) {
	if (u == p[u]) return u;
	return p[u]=find(p[u]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> cnt[i], p[i] = i;
	while (m--) {
		int a, b;
		cin >> a >> b;
		a = find(a), b = find(b);
		if (a == b) cout << -1;
		else if (cnt[a] == cnt[b]) {
			p[max(a, b)] = min(a, b);
			cnt[min(a, b)] += cnt[max(a, b)]/2;
			cnt[max(a, b)] /= 2;
			cout << min(a, b);
		}
		else if (cnt[a] > cnt[b]) {
			p[b] = a;
			cnt[a] += cnt[b]/2;
			cnt[b] /= 2;
			cout << a;
		}
		else {
			p[a] = b;
			cnt[b] += cnt[a]/2;
			cnt[a] /= 2;
			cout << b;
		}
		cout << "\n";
	}
	return 0;
}