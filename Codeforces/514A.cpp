#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] >= '5' && s[i] <= '9') {
			if (s[i] != '9' || i != 0) s[i] = '0'+'9'-s[i];
		}
	}
	cout << s;
	return 0;
}