#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long int sum=(n*(n+1))/2;
	if (sum%2 == 0) cout << "YES";
	else cout << "NO";
	return 0;
}
