#include <bits/stdc++.h>
using namespace std;

struct Node {
	int idx;
	bool male;
	bool alive;
	Node* old;
	Node* mid;
	Node* young;
};

map<int,Node*> mp;

void createNode(int idx, char s) {
	Node* node = new Node();
	node->idx = idx;
	node->male = (s == 'M');
	node->alive = true;
	node->old = NULL;
	node->mid = NULL;
	node->young = NULL;
	mp[idx] = node;
}

bool found=false;
int king=1;

void dfs(Node* root) {
	if (root == NULL || found) return;
	if (root->male && root->alive) {
		king = root->idx;
		cout << root->idx << "\n";
		found = true;
		return;
	}
	dfs(root->old);
	dfs(root->mid);
	dfs(root->young);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x;
	char t;
	cin >> n;
	createNode(1, 'M');
	int idx=2;
	cout << "1\n";
	while (n--) {
		cin >> x >> t;
		if (t == 'D') {
			mp[x]->alive = false;
			if (x == king) {
				found = false;
				dfs(mp[1]);	
			}
		}
		else {
			createNode(idx, t);
			if (mp[x]->mid == NULL && mp[x]->young == NULL) {	
				if (mp[x]->old == NULL) mp[x]->old = mp[idx];
				else mp[x]->mid = mp[idx];
			}
			else mp[x]->young = mp[idx];
			idx++;
		}
	}
	return 0;
}