#include <bits/stdc++.h>
using namespace std;

#define ll long long

int a[5000009];
ll l[5000009], r[5000009];
stack<pair<int,int>> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	// stack index, cnt
	ll sum=0;
	for (int i = 1; i <= n; i++) {
		int cnt=1;
		while (!st.empty() && a[i] < a[st.top().first]) {
			sum -= (ll)a[st.top().first]*st.top().second;
			cnt += st.top().second;
			st.pop();
		}
		sum += (ll)a[i]*cnt;
		l[i] = sum;
		st.push({i, cnt});
	}
	while (!st.empty()) st.pop();
	sum=0;
	for (int i = n; i >= 1; i--) {
		int cnt=1;
		while (!st.empty() && a[i] < a[st.top().first]) {
			sum -= (ll)a[st.top().first]*st.top().second;
			cnt += st.top().second;
			st.pop();
		}
		sum += (ll)a[i]*cnt;
		r[i] = sum;
		st.push({i, cnt});
	}
	ll ans=0;
	// for (int i = 1; i <= n; i++) cout << l[i] << " "; cout << "\n";
	// for (int i = 1; i <= n; i++) cout << r[i] << " "; cout << "\n";
	for (int i = 1; i <= n; i++) ans = max(ans, l[i]+r[i]-(ll)a[i]);
	cout << ans;
	return 0;
}