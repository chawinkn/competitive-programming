#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

bool cmp1(pair<int,int> a, pair<int,int> b) {
	if (a.f != b.f) return a.f > b.f;
	return a.s < b.s;
}

bool cmp2(pair<int,int> a, pair<int,int> b) {
	if (a.f != b.f) return a.f < b.f;
	return a.s > b.s;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int,int>> p(n), ans;
	for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
	sort(p.begin(), p.end(), cmp1);
	int mx=0;
	for (auto [x, y] : p) {
		if (y >= mx) {
			mx = y;
			ans.push_back({x, y});
		}
	}
	sort(ans.begin(), ans.end(), cmp2);
	for (auto [x, y] : ans) cout << x << " " << y << "\n";
	return 0;         
}