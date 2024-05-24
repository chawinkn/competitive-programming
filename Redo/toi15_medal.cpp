#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
   	ios_base::sync_with_stdio(false); cin.tie(NULL);
   	int n;
   	cin >> n;
   	vector<int> t(n), h(n), res(n);
   	for (auto& i : t) cin >> i; 
	for (auto& i : h) cin >> i;
   	sort(t.begin(), t.end()); 
	sort(h.begin(), h.end()); 
	reverse(h.begin(), h.end());
   	for (int i = 0; i < n; i++) res[i] = t[i]+h[i]; 
	sort(res.begin(), res.end());
   	ll ans=0;
   	for (int i = 0; i < n-1; i++) ans += abs(res[i]-res[i+1]);
   	cout << ans;
	return 0;
}