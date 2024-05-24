#include <bits/stdc++.h>
using namespace std;

// D&C

#define ll long long

int A[100009];
ll ans=0;

void merge(int l, int m, int r) {
	vector<int> temp;
	int i=l, j=m+1;
	while (i <= m && j <= r) {
		if (A[i] <= A[j]) temp.push_back(A[i++]);
		else {
			temp.push_back(A[j++]);
			ans += m-i+1;
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
	for (int i = 1; i <= n; i++) cin >> A[i];
	mergeSort(1, n);
	cout << ans;
	return 0;
}