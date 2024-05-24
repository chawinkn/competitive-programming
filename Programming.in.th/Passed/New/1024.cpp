#include <bits/stdc++.h>
using namespace std;

int qs[1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, mn=INT_MAX, ans1=1, ans2=1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> qs[i];
		qs[i] += qs[i-1];
	}
	for (int i = 1; i <= n-2; i++) {
		for (int j = i+1; j <= n-1; j++) {
			int f=qs[i], s=qs[j]-qs[i], t=qs[n]-qs[j];
			int d=max({f,s,t})-min({f,s,t});
			if (d < mn) {
				mn = d;
				ans1 = i+1;
				ans2 = j+1;
			}
		}
	}
	cout << ans1 << " " << ans2;
	return 0;
}
