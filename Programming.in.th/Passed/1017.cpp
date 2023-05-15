#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int s[n][n], ss[n*n], ii=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
			ss[ii] = s[i][j];
			ii++;
		}
	}
	
	int ld = 0, rd = 0;
	for (int i = 0; i < n; i++) {
	    ld += s[i][i];
	    rd += s[i][n-1-i];
	}
	
	for (int i = 0; i < n*n; i++) {
		for (int j = i+1; j < n*n; j++) {
			if (ss[i] == ss[j]) {
				cout << "No";
				return 0;
			}
		}
	}
	
	if (ld != rd) {
		cout << "No";	
		return 0;
	}
	else {
		for (int i = 0; i < n; i++) {
	    	int r = 0, c = 0;   
	    	for (int j = 0; j < n; j++) {
	        	r += s[i][j];
	        	c += s[j][i];
	    	}
		    if (r != c || c != ld) {
		    	cout << "No";
		        return 0;
			}
		}
	}
	
	cout << "Yes";
    return 0;
}
