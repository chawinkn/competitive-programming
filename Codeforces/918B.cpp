#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	string name, ip, command;
	unordered_map<string,string> mp;
	for (int i = 1; i <= n; i++) {
		cin >> name >> ip;
		ip += ";";
		if (mp.find(ip) == mp.end()) mp[ip] = "#"+name;
	}
	for (int i = 1; i <= m; i++) {
		cin >> command >> ip;
		cout << command << " " << ip << " " << mp[ip] << "\n";
	}
	return 0;
}