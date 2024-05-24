#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

pair<int,int> l[1007], r[1007], a, b;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> l[i].f >> l[i].s >> r[i].f >> r[i].s;
	while (m--) {
		cin >> a.f >> a.s >> b.f >> b.s;
		int cnt=0;
		for (int i = 0; i < n; i++) {
			if (a.f >= r[i].f || b.f <= l[i].f || a.s <= r[i].s || b.s >= l[i].s) continue;
			cnt++; 
		}
		cout << cnt << "\n";
	}
	return 0;
}