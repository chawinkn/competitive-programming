#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

vector<pair<int, int>> mx(200001, {0, 0});
vector<pair<int, int>> mn(200001, {350, 350});
vector<pair<int, int>> dpmx(200001), dpmn(200001);
int v[200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int h, w, q, n, a, b, l=200000, r=0, ans;
	cin >> h >> w >> q;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> n;
			if (!v[n]) v[n] = 1;
			l = min(l, n);
			r = max(r, n);
			mx[n] = {max(i, mx[n].f), max(j, mx[n].s)};
			mn[n] = {min(i, mn[n].f), min(j, mn[n].s)};
		}
	}
	dpmx[r] = {mx[r].f, mx[r].s};
	dpmn[r] = {mn[r].f, mn[r].s};
	for (int i = r-1; i >= l; i--) {
		dpmx[i] = {max(mx[i].f, dpmx[i+1].f), max(mx[i].s, dpmx[i+1].s)};
		dpmn[i] = {min(mn[i].f, dpmn[i+1].f), min(mn[i].s, dpmn[i+1].s)};
	}
	for (int i = 0; i < q; i++) {
		ans = 0;
		cin >> a >> b;
		if (a == 1 && v[b]) ans = 2*(mx[b].f-mn[b].f+mx[b].s-mn[b].s+2);	
		else if (a == 2 && b <= r) ans = 2*(dpmx[b].f-dpmn[b].f+dpmx[b].s-dpmn[b].s+2);		
		cout << ans << "\n";
	}
	return 0;
}
