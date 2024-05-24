#include <bits/stdc++.h>
using namespace std;

long long int cnt[10001];

int main() {
	int n;
	cin >> n;
	cnt[1] = 6;
	cnt[2] = 28;
	for (int i = 3; i <= n; i++) cnt[i] = 4*cnt[i-1]-(i+1)*(i+1);
	for (int i = 0; i <= n; i++) cout << cnt[i] << "\n";
	return 0;
}
