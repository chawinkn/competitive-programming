#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int x[3][3]={0}, y[3][3]={0};
		char c;
		int xx, yy;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> c;
				if (c == '?') {
					yy=i, xx=j;
					continue;	
				}
				x[j][c-'A']++;
				y[i][c-'A']++;
			}
		}	
		for (int i = 0; i < 3; i++) {
			if (!x[xx][i]) cout << (char)('A'+i) << "\n";
		}
	}
	return 0;
}