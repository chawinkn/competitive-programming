#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long int n, M=1e9+7;
	cin >> n;
	cout << ((((n%M)*(n%M))%M)*(n%M))%M;
	return 0;
}
