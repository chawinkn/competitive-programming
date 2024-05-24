#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> t(n), h(n), s(n);
	for (int i = 0; i < n; i++) cin >> t[i];
	for (int i = 0; i < n; i++) cin >> h[i];
	sort(t.begin(), t.end(), greater<int>());
	sort(h.begin(), h.end());
	for (int i = 0; i < n; i++) s[i] = t[i]+h[i];
	sort(s.begin(), s.end());
	int ans=0;
	for (int i = 0; i < n-1; i++) ans += abs(s[i]-s[i+1]);
	cout << ans;
	return 0;	
}