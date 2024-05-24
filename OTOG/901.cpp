#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

ll a[5000009], L[5000009], R[5000009];
stack<pair<int,int>> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ll sum=0;
	for (int i = 1; i <= n; i++) {
		int cnt=1;
		while (!st.empty() && a[i] <= a[st.top().f]) {
			sum -= a[st.top().f]*st.top().s;
			cnt += st.top().s;
			st.pop();
		}
		sum += a[i]*cnt;
		L[i] = sum;
		st.push({i, cnt});
	}
	while (!st.empty()) st.pop();
	sum = 0;
	for (int i = n; i >= 1; i--) {
		int cnt=1;
		while (!st.empty() && a[i] <= a[st.top().f]) {
			sum -= a[st.top().f]*st.top().s;
			cnt += st.top().s;
			st.pop();
		}
		sum += a[i]*cnt;
		R[i] = sum;
		st.push({i, cnt});
	}
	// for (int i = 1; i <= n; i++) cout << L[i] << " "; cout << "\n";
	// for (int i = 1; i <= n; i++) cout << R[i] << " "; cout << "\n";
	ll ans=0;
	for (int i = 1; i <= n; i++) ans = max(ans, L[i]+R[i]-a[i]);
	cout << ans;
	return 0;
}