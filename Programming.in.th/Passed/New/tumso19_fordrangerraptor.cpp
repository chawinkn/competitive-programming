#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < 2*n-1; i++) {
		for (int k = 0; k < 4; k++) {
			for (int j = 0; j < n; j++) {
				if (k == 0) {
					if (i == 0 || i == n-1) cout << '#';
					else if (j == 0) cout << '#';
					else cout << ' ';
				}
				else if (k == 1) {
					if (i == 0 || i == 2*n-2 || j == 0 || j == n-1) cout << '#';
					else cout << ' ';
				}
				else if (k == 2) {
					if (i <= n-1) {
						if (i == 0 || i == n-1 || j == 0 || j == n-1) cout << '#';
						else cout << ' ';
					}
					else {
						if (j == 0 || j == i-n+1) cout << '#';
						else cout << ' ';
					}
				}
				else {
					if (i == 0 || i == 2*n-2) {
						if (j != n-1) cout << '#';
						else cout << ' ';
					} 
					else {
						if (j == 0 || j == n-1) cout << '#';
						else cout << ' ';
					}
				}
			}
			cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}
