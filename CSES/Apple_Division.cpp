#include <bits/stdc++.h>
using namespace std;

int n, arr[21];
long long total=0, ans=INT_MAX;

void combi(int s, int k, int v[], long long int sum) {
	if (k == 0) {
		ans = min(ans, abs(total-2*sum));
		return;
	}
	for (int i = s; i < n; i++) {
		v[i] = 1;
		combi(i+1, k-1, v, sum+arr[i]);
		v[i] = 0;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		total += arr[i];	
	}
	for (int i = 0; i <= n/2; i++) {
		int v[21]={0};
		combi(0, i, v, 0);
	}
	cout << ans;
	return 0;
}
