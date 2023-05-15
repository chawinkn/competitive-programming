#include <bits/stdc++.h>
using namespace std;

int x[101], y[101];

int main() {
	int n;
	double a, m=0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	for (int i = 0; i < n-2; i++) {
		for (int j = i+1; j < n-1; j++) {
			for (int k = j+1; k < n; k++) {
				a = abs(x[i]*y[j]+x[j]*y[k]+x[k]*y[i]-y[i]*x[j]-y[j]*x[k]-y[k]*x[i]);
				m = max(m, a/2);
			}
		}
	}
	printf("%.3lf", m);
	return 0;
}
