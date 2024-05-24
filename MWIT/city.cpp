#include <bits/stdc++.h>
using namespace std;

int h[3000009], l[3000009], cnt[3000009];
stack<int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		l[i] = i;
		while (!st.empty() && h[i] > h[st.top()]) {
			if (cnt[st.top()]+1 > cnt[i]) {
				cnt[i] = cnt[st.top()]+1;
				l[i] = l[st.top()];
			}
			else if (cnt[st.top()]+1 == cnt[i]) {
				l[i] = min(l[i], l[st.top()]);
			}
			st.pop();
		}
		st.push(i);
	}
	int ans, mx=0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] > mx) {
			ans = l[i];
			mx = cnt[i]; 
		}
	}
	if (mx == 0) cout << -1;
	else cout << ans << " " << mx;
	return 0;
}