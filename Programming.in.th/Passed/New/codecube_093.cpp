#include<bits/stdc++.h>
using namespace std;

double x[1009], y[1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	int ans=(n*(n-1)*(n-2))/6;
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			for (int k = j+1; k <= n; k++) {
				double m1=abs(y[i]-y[j])/abs(x[i]-x[j]);
				double m2=abs(y[k]-y[j])/abs(x[k]-x[j]);
				double m3=abs(y[i]-y[k])/abs(x[i]-x[k]);
				if (m1 == m2 && m2 == m3) ans--;
			}
		}
	}
	cout << ans;
	return 0;
}