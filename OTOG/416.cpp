#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

int main() {
	int n;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		vector<int> h(n);
		for (auto &i : h) scanf("%d", &i);
		ll ans=0;
		stack<pair<int,int>> st;
		for (int i = 0; i < n; i++) {
			int start = i;
			while (!st.empty() && h[i] < st.top().s) {
				ans = max(ans, st.top().s*(ll)(i-st.top().f));
				start = st.top().f, st.pop();
			}
			st.push({start, h[i]});
		}
		while (!st.empty()) {
			ans = max(ans, st.top().s*(ll)(n-st.top().f));
			st.pop();
		}
		printf("%lld\n", ans);
	}
	return 0;
}