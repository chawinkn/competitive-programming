#include <bits/stdc++.h>
using namespace std;

// D&C + Quicksum 1D

#define ll long long

int A[100009];
ll qs[100009], ans=0;

void merge(int l, int m, int r) {
	vector<int> temp;
	cout << l << " " << r << "\n";
	for (int i = l; i <= r; i++) qs[i] = qs[i-1]+A[i];
	for (int i = 1; i <= 6; i++) cout << qs[i] << " ";
	cout << "\n";
	int i=l, j=m+1;
	while (i <= m && j <= r) {
		if (A[i] <= A[j]) temp.push_back(A[i++]);
		else {
			ans += A[j]*(m-i+1)+qs[m]-qs[i-1];
			temp.push_back(A[j++]);
		}
	}
	while (i <= m) temp.push_back(A[i++]);
	while (j <= r) temp.push_back(A[j++]);
	for (int i = 0; i < temp.size(); i++) A[i+l] = temp[i];
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
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		A[b] = a;
	}
	mergeSort(1, n);
	cout << ans;
	return 0;
}