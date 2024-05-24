#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define f first
#define s second
 
int a[500009], b[500009], cnt[500009];
ll x, qs[500009];
deque<pair<int,int>> mx, mn;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, p, y, z;
	cin >> n >> p >> x >> y >> z;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		qs[i] = qs[i-1]+a[i];	
	}
	for (int i = 1; i <= n; i++) cin >> b[i];
	ll ans=0;
	for (int i = 1, l = 1; i <= n; i++) {
		while (!mx.empty() && mx.back().f < a[i]) mx.pop_back();
		while (!mn.empty() && mn.back().f > a[i]) mn.pop_back();
		mx.push_back({a[i], i});
		mn.push_back({a[i], i});
		cnt[b[i]]++;
		if (y != -1) {
			while (abs(mx.front().f-mn.front().f) > y) {
				cnt[b[l]]--;
				l++;
				while (!mx.empty() && mx.front().s < l) mx.pop_front();
				while (!mn.empty() && mn.front().s < l) mn.pop_front();
			}
		}
		if (z != -1) {
			while (cnt[b[i]] > z) {
				cnt[b[l]]--;
				l++;
			}
		}
		while (qs[i]-qs[l-1] > x) {
			cnt[b[l]]--;
			l++;
		}
		while (!mx.empty() && mx.front().s < l) mx.pop_front();
		while (!mn.empty() && mn.front().s < l) mn.pop_front();
		ans += i-l+1;
		cout << l << " " << i << " " << ans << "\n";
	}
	cout << ans;
	return 0;
}