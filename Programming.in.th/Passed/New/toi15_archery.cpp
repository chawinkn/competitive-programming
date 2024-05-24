#include <bits/stdc++.h>
using namespace std;

#define ll long long

// ll qsh[500009], qsx[500009];
ll qsx[500009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n;
	int mn=1e9;
	cin >> n;
	vector<pair<int,int>> box(n+1);
	for (int i = 1; i <= n; i++) cin >> box[i].second, mn = min(mn, box[i].second);
	for (int i = 1; i <= n; i++) cin >> box[i].first;
	sort(box.begin()+1, box.end());
	for (int i = 1; i <= n; i++) {
		auto [x,h]=box[i];
		// qsh[i] = qsh[i-1]+h;
		qsx[i] = qsx[i-1]+x;
	}
	int p;
	ll sumh=0, ans=1e18;
	for (int i = 1; i <= n; i++) {
		auto [x,h]=box[i];
		if (x > mn) continue;
		// ll L=qsx[i-1]+qsh[i-1]-(i-1)*(ll)x;
		ll L=qsx[i-1]+sumh-(i-1)*(ll)x;
		ll R=qsx[n]-qsx[i]-(n-i)*(ll)x;
		sumh += h;
		if (L+R < ans) ans = L+R, p = x;
		else if (L+R == ans) p = min(p, x);
	}
	cout << p << " " << ans;
	return 0;
}