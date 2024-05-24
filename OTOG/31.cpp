#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, sum=0;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		sum += x[i];
	}
	sort(x.begin(), x.end());
	for (int i = n-2; i >= n/2; i-=2) sum -= x[i];
	cout << sum;
	return 0;
}