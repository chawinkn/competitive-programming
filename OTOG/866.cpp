#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int h[1000009], r[1000009], H[1000009];
stack<pair<int,int>> st; // h idx

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = n; i >= 1; i--) r[i] = max(r[i+1], h[i]);
	int mx=0;
	for (int i = 1; i <= n; i++) {
		mx = max(mx, h[i]);
		H[i] = min(mx, r[i]);
	}
	int ans=0;
	for (int i = 1; i <= n; i++) {
		int start=i;
		while (!st.empty() && H[i] < st.top().f) {
			ans = max(ans, st.top().f*(i-st.top().s-1));
			start = st.top().s;
			st.pop();
		}
		st.push({H[i], start});
	}
	while (!st.empty()) ans = max(ans, st.top().f*(n-st.top().s-1)), st.pop();
	cout << ans;
	return 0;	
}