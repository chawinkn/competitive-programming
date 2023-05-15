#include <bits/stdc++.h>
using namespace std;

long long int sum=0, d=0, m=1, c=1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, num;
	char t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t >> num;
		if (t == '-') d += num;
		else if (t == '+') sum += num;
		else if (t == 'x') {
			if (num == 0) c = 0;
			else m *= num;
		}
	}
	cout << sum*m-d*c;
	return 0;
}
