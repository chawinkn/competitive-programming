#include <bits/stdc++.h>
using namespace std;

#define ll long long

int h[200009], l[200009], r[200009];
vector<int> LIS;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		auto it=lower_bound(LIS.begin(), LIS.end(), h[i]);
		l[i] = it-LIS.begin();
		if (it == LIS.end()) LIS.push_back(h[i]);
		else *it = h[i];
	}
	LIS.clear();
	for (int i = n-1; i >= 0; i--) {
		auto it=lower_bound(LIS.begin(), LIS.end(), h[i]);
		r[i] = it-LIS.begin();
		if (it == LIS.end()) LIS.push_back(h[i]);
		else *it = h[i];
	}
	vector<int> temp(n);
	for (int i = 0; i < n; i++) temp[i] = l[i]+r[i]+2;
	sort(a.begin(), a.end()), sort(temp.begin(), temp.end());

	ll ans=0;
	for (int i = n-1; i >= 0; i--) ans += (ll)a[i]*temp[i];
	cout << ans;
	return 0;   
}