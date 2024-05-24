#include <bits/stdc++.h>
using namespace std;

double a[200009];
int b[200009], c[200009];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
	double k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i] >> b[i] >> c[i];	
	}
	double l=0, r=10000;
	while (r-l > 1e-7) {
		double m=(l+r)/2, power=0;
		double x=m/10000;
		for (int i = 1; i <= n; i++) {
			power += (double)(a[i]*x)+(double)pow(x, b[i])+(double)pow(x, c[i]);
		}
		if (power >= k) r = m;
		else l = m+0.00001;
	}
	printf("%.2lf", ceil(l)/100);
    return 0;
}