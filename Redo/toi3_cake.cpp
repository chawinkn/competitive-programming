#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, cnt=0;
	cin >> n;
	while (n--) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		cnt += 8*a+6*b+4*c+2*d+e;
	}
	cout << cnt/8+(cnt%8!=0);
	return 0;
}