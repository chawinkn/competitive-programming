#include <bits/stdc++.h>
using namespace std;

int w[20]={1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i < 20; i++) w[i] = w[i-1]*3;
	int l=n, r=0;
	for (int i = 0; i < 20 && l != r; i++) {
		int rem=((l-r)/w[i])%3;
		if (rem == 1) {
			
		}
		else if (rem == 2) {
			
		}
	}
	return 0;
}