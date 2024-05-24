#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll arr1[2009], arr2[2009], ans=0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr1[i];
	for (int i = 0; i < n; i++) cin >> arr2[i];
	sort(arr1, arr1+n);
	sort(arr2, arr2+n);
	for (int i = 0; i < n; i++) ans += abs(arr1[i]-arr2[i]);
	cout << ans;
	return 0;
}
