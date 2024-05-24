#include <bits/stdc++.h>
using namespace std;

#define ll long long

int a[100009], temp[100009];
ll qs[100009], ans=0;

void merge(int l, int m, int r) {
	int i=l, j=m+1, k=0;
	for (int i = l; i <= r; i++) qs[i] = qs[i-1]+a[i];
	while (i <= m && j <= r) {
		if (a[i] > a[j]) {
			ans += qs[m]-qs[i-1]+(m-i+1)*a[j];
			temp[k++] = a[j++];
		}
		else temp[k++] = a[i++];
	}
	while (i <= m) temp[k++] = a[i++]; 
	while (j <= r) temp[k++] = a[j++];
	for (int i = 0; i < k; i++) a[i+l] = temp[i];
}

void mergeSort(int l, int r) {
	int m=(l+r)/2;
	if (l >= r) return;
	mergeSort(l, m);
	mergeSort(m+1, r);
	merge(l, m, r);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int A, B;
		cin >> A >> B;
		a[B] = A;
	}
	mergeSort(1, n);
	cout << ans;
	return 0;
}