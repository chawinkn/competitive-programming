#include <bits/stdc++.h>
using namespace std;

int n, ans=0, arr[1000009], temp[1000009];

// Inversion Count ai > aj ; i < j

void merge(int l, int m, int r) {
	int i=l, j=m+1, k=l;
	int now=0;
	while (i <= m && j <= r) {
		if (arr[i] > arr[j]) {
			temp[k++] = arr[j++];
			now += m-i+1;
			ans += m-i+1;
		}
		else {
			temp[k++] = arr[i++];
		}
	}
	
	for (int i = l; i <= m; i++) cout << arr[i] << " ";
	cout << "  ";
	for (int i = m+1; i <= r; i++) cout << arr[i] << " ";
	cout << "\n" << "cnt = " << now << "\n\n";

	while (i <= m) temp[k++] = arr[i++];
	while (j <= r) temp[k++] = arr[j++];
	for (int i = l; i <= r; i++) arr[i] = temp[i];
}

void mergeSort(int l, int r) {
	if (l >= r) return;
	int m=(l+r)/2;
	mergeSort(l, m);
	mergeSort(m+1, r);
	merge(l, m, r);
}

// void mergeSort() {
// 	for (int sz = 1; sz < n; sz *= 2) {
// 		for (int l = 0; l < n; l += 2*sz) {
// 			int r=min(l+2*sz-1, n-1);
// 			int m=(l+r)/2;
// 			merge(l, m, r);
// 		}
// 	}
// }

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	mergeSort(0, n-1);
	// mergeSort();
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << "\n" << ans << "\n";
	return 0;
}