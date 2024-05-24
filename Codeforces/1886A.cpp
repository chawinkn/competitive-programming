#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
//		i = 1, j = n;
//		i+j+k = n
//		k = n-i-j;
		int check=0;
		for (int i = 1; i <= n; i++) {
			if (i%3 == 0) continue;
			for (int j = i+1; j <= n; j++) {
				if (j%3 == 0) continue;
				int k=n-i-j;
				if (i+j <= n && k != i && k != j && k%3 != 0) {
					cout << "YES\n" << i << " " << j << " " << k << "\n";
					check = 1;
					break;
				}
			}
			if (check) break;
		}	
		if (!check) cout << "NO\n";
	}
	return 0;
}