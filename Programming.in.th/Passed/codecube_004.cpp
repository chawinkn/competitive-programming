#include <bits/stdc++.h>
using namespace std;

long long int arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long int cnt=0, g=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		g = __gcd(arr[i], g);
	}
	for (int i = 0; i < n; i++) {
		cnt += arr[i] / g;
	}
	cout << cnt;
	return 0;
}
