#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, num, m=0;
	long long int cnt=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;	
		m = max(num, m);
		cnt += m-num;
	}
	cout << cnt;
	return 0;
}
