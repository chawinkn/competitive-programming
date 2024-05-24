#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int n;
	cin >> n;
	vector<pair<ll,ll>> arr;
	for (int i = 0; i < n; i++) {
		int d, c;
		cin >> d >> c;
		arr.push_back({c, d});
	}
	sort(arr.begin(), arr.end());
	ll sum=0, mx=1, cnt=0, cost=0;
	double mxr=0;
	for (auto [c,d] : arr) {
		sum += d;
		mx = max(mx, c);
		double r=(double)sum/(double)mx;
		if (r > mxr) {
			mxr = r;
			cnt = sum;
			cost = mx;
		}
	}
	cout << cnt << " " << cost;
	return 0;
}