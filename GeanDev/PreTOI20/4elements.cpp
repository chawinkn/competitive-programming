#include <bits/stdc++.h>
using namespace std;

// 12/100

#define ll long long

ll A[100009], B[100009], C[100009], D[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) cin >> B[i];
	for (int i = 1; i <= n; i++) cin >> C[i];
	for (int i = 1; i <= n; i++) cin >> D[i];
	ll ans=9e18;
	for (int i = 1; i <= n; i++) ans = min(ans, (A[i]-C[i])*(A[i]-C[i])+(B[i]-D[i])*(B[i]-D[i]));
	cout << ans;
	return 0;
}

// 1 1 2 3 5 5 6 
// 1 2 3 2 4 6 5