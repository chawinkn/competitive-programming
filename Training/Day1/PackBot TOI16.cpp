#include <bits/stdc++.h>
using namespace std;

// Stack

stack<char> st;
stack<int> gift;
map<char,int> order, percent;
vector<char> post;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	cin >> s;
	order['1'] = 1, order['2'] = 2, order['3'] = 3;
	percent['1'] = 104, percent['2'] = 108, percent['3'] = 116;
	for (auto i : s) {
		if (i >= 'A' && i <= 'Z') post.push_back(i);
		else if (i == '[') st.push(i);
		else if (i == ']') {
			while (!st.empty() && st.top() != '[') post.push_back(st.top()), st.pop();
			st.pop();
		}
		else {
			while (!st.empty() && order[i] <= order[st.top()]) post.push_back(st.top()), st.pop();
			st.push(i);
		}
	}
	while (!st.empty()) post.push_back(st.top()), st.pop();
	for (auto i : post) {
		if (i >= 'A' && i <= 'Z') gift.push(20);
		else {
			int a=gift.top(); gift.pop();
			int b=gift.top(); gift.pop();
			gift.push((a+b)*percent[i]/100);
		}
	}
	cout << gift.top();
	return 0;
}