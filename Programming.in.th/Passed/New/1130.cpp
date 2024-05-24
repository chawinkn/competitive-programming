#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 49999

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	ll num, sum , ans=0;
	cin >> n >> sum;
	for (int i = 1; i < n; i++) {
		cin >> num;
		ans += i*num-sum; // - sum from [0,i)
		ans %= M;
		sum += num;
	}
	for (int i = 2; i <= n-2; i++) {
		ans *= i;
		ans %= M;
	}
	cout << ans;
	return 0;
}

