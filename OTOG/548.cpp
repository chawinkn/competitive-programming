#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, num;
    string t;
    cin >> n;
    while (n--) {
    	cin >> t;
    	if (t == "push") {
    		cin >> num;
    		q.push(num);
		}
		else {
			if (q.empty()) cout << "null\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
	}
    return 0;
}