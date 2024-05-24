#include <bits/stdc++.h>
using namespace std;

// DP

int J[1009], K[1009], day[1009][1009], mins[1009][1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m, n;
	cin >> m >> n;
	day[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> J[i];
		int dj=day[i-1][0], mj=mins[i-1][0];
		mj += J[i];
		if (mj > m) dj++, mj = J[i];
		day[i][0] = dj, mins[i][0] = mj;
	}
	for (int i = 1; i <= n; i++) {
		cin >> K[i];
		int dk=day[0][i-1], mk=mins[0][i-1];
		mk += K[i];
		if (mk > m) dk++, mk = K[i];
		day[0][i] = dk, mins[0][i] = mk;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int dj=day[i-1][j], mj=mins[i-1][j];
			mj += J[i];
			if (mj > m) dj++, mj = J[i];
			int dk=day[i][j-1], mk=mins[i][j-1];
			mk += K[j];
			if (mk > m) dk++, mk = K[j];
			if (dj < dk) day[i][j] = dj, mins[i][j] = mj;
			else if (dk < dj) day[i][j] = dk, mins[i][j] = mk;
			else day[i][j] = dj, mins[i][j] = min(mj, mk);
		}
	}
	cout << day[n][n] << "\n" << mins[n][n];
	return 0;
}