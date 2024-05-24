#include <bits/stdc++.h>
using namespace std;

vector<char> post;
map<char,int> order, per;
stack<char> st;
stack<int> gift;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	cin >> s;
	order['1'] = 1, order['2'] = 2, order['3'] = 3;
	per['1'] = 4, per['2'] = 8, per['3'] = 16;
	for (auto i : s) {
		if (i >= 'A' && i <= 'Z') post.push_back(i);
		else if (i == '[') st.push(i);
		else if (i == ']') {
			while (!st.empty() && st.top() != '[')
				post.push_back(st.top()), st.pop();
			st.pop();
		}
		else {
			while (!st.empty() && order[i] <= order[st.top()]) 
				post.push_back(st.top()), st.pop();
			st.push(i);
		}
	}
	while (!st.empty()) 
		post.push_back(st.top()), st.pop();
		
	for (auto i : post) {
		if (i >= 'A' && i <= 'Z') gift.push(20);
		else {
			int a=gift.top(); gift.pop();
			int b=gift.top(); gift.pop();
			gift.push(a+b+(per[i]*(a+b))/100);
		}
	}
	cout << gift.top();
	return 0;
}