#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	sort(x.begin(), x.end());  
	ll sum=0;
	for (int i = 0; i < n; i++) {
		if (sum+1 < x[i]) break;
		sum += x[i];
	}
	cout << sum+1;
	return 0;
}