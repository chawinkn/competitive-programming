#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int,int>> t;
	while (n--) {
		int a, d;
		cin >> a >> d;
		t.push_back({a,d});
	}
	sort(t.begin(), t.end());
	ll now=0, ans=0;
	for (auto [a,d] : t) {
		now += a;
		ans += d-now;
	}
	cout << ans;
	return 0;
}