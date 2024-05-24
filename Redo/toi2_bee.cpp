#include <bits/stdc++.h>
using namespace std;

int work[29], soldier[29];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	work[0] = 1;
	for (int i = 1; i <= 24; i++) {
		work[i] = soldier[i-1]+work[i-1]+1;
		soldier[i] = work[i-1];
	} 
	int n;
	while (cin >> n) {
		if (n == -1) break;
		cout << work[n] << " " << work[n]+soldier[n]+1 << "\n";
	}
	return 0;
}