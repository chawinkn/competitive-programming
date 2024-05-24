#include <bits/stdc++.h>
using namespace std;

int m[5]={8,6,4,2,1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, num, sum=0;
	cin >> n;
	while (n--) {
		for (int i = 0; i < 5; i++) {
			cin >> num;
			sum += num*m[i];
		}
	}
	if (sum%8 == 0) cout << sum/8;
	else cout << sum/8+1;
	return 0;
}
