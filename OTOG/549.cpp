#include <bits/stdc++.h>
using namespace std;

stack<int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, num;
    string t;
    cin >> n;
    while (n--) {
    	cin >> t;
    	if (t == "push") {
    		cin >> num;
    		st.push(num);
		}
		else {
			if (st.empty()) cout << "null\n";
			else {
				cout << st.top() << "\n";
				st.pop();
			}
		}
	}
    return 0;
}