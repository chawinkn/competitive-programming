#include <bits/stdc++.h>
using namespace std;

// Quicksum 1D + Stack

#define ll long long

void solve() {
	int n;
	cin >> n;
	vector<ll> p(n+1), qs(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		qs[i] = qs[i-1]+p[i];
	}
	ll ans=0;
	stack<int> st;
	vector<int> L(n+1), R(n+1);
	for (int i = 1; i <= n; i++) {
		while (!st.empty() && p[i] >= p[st.top()]) {
			L[i] = max(L[i], L[st.top()]+i-st.top());
			st.pop();
		}
		L[i] = max(L[i], 1);
		st.push(i);
	}
	while (!st.empty()) st.pop();
	for (int i = n; i >= 1; i--) {
		while (!st.empty() && p[i] >= p[st.top()]) {
			R[i] = max(R[i], R[st.top()]+st.top()-i);
			st.pop();
		}
		R[i] = max(R[i], 1);
		st.push(i);
	}
	for (int i = 1; i <= n; i++) {
		// int l=i, r=i;
		// while (l > 1 && p[l-1] <= p[i]) l--;
		// while (r < n && p[r+1] <= p[i]) r++;
		int l=i-L[i]+1, r=i+R[i]-1;
		ll infected=p[i]*(r-l+1);
		ans = max(ans, infected*(qs[n]-(qs[r]-qs[l-1])));
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}