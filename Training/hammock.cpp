#include <bits/stdc++.h>
using namespace std;

int h[2000009], mxl[2000009], l[2000009], r[2000009];
stack<int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		mxl[i] = max(mxl[i-1], h[i]);
	}
	int mx=h[n];
	for (int i = n; i >= 1; i--) {
		h[i] = max(h[i], mx);
		mx = max(mx, h[i]);
		h[i] = min(h[i], mxl[i]);
	}
	int ans=0;
	for (int i = 1; i <= n; i++) {
		l[i] = i;
		while (!st.empty() && h[i] <= h[st.top()]) {
			l[i] = min(l[i], l[st.top()]);
			st.pop();
		}
		st.push(i);
	}
	for (int i = n; i >= 1; i--) {
		r[i] = i;
		while (!st.empty() && h[i] <= h[st.top()]) {
			r[i] = max(r[i], r[st.top()]);
			st.pop();
		}
		st.push(i);
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, h[i]*(r[i]-l[i]));
	}
	cout << ans;
	return 0;
}