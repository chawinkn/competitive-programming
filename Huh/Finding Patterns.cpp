#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	cin >> s;
	int n=s.length(), k;
	cin >> k;
	// O(K(N+M))
	while (k--) {
		string p;
		cin >> p;
		int m=p.length();
		bool found=false;
		vector<int> LPS(m, 0);
		int i=1, j=0;
		while (i < m) {
			if (p[i] == p[j]) LPS[i] = j+1, i++, j++;
			else if (j == 0) LPS[i] = 0, i++;
			else j = LPS[j-1];
		}
		i=0, j=0;
		while (i < n) {
			if (s[i] == p[j]) i++, j++;
			else if (j == 0) i++;
			else j = LPS[j-1];
			
			if (j == m) {
				found = true;
				break;
			}
		}
		cout << (found ? "YES" : "NO") << "\n";
	} 
	return 0;
}