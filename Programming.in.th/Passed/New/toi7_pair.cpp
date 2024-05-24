#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll a[100009], qs[100009], temp[100009], ans=0;

void merge(int l, int m, int r) {
	for (int i = l; i <= r; i++) qs[i] = qs[i-1]+a[i];
	int i=l, j=m+1, k=l;
	while (i <= m && j <= r) {
		if (a[i] > a[j]) {
			ans += qs[m]-qs[i-1]+a[j]*(m-i+1);
			temp[k++] = a[j++];
		}
		else temp[k++] = a[i++];
	}
	while (i <= m) temp[k++] = a[i++];
	while (j <= r) temp[k++] = a[j++];
	for (int i = l; i <= r; i++) a[i] = temp[i];
}

void mergeSort(int l, int r) {
	if (l >= r) return;
	int m=(l+r)/2;
	mergeSort(l, m);
	mergeSort(m+1, r);
	merge(l, m, r);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int A, B;
		cin >> A >> B;	
		a[B] = A;
	}
	mergeSort(1, n);
	cout << ans;
	return 0;
}