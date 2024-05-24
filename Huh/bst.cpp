#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};

struct TreeNode* createNode(int val) {
	TreeNode* node = new TreeNode();
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}
	
struct TreeNode* add(TreeNode* root, int val) {
	if (root == NULL) return createNode(val);
	if (val < root->val) root->left = add(root->left, val);
	else root->right = add(root->right, val);
	return root;	
}

void preorder(TreeNode* root) {	
	if (root == NULL) return;
	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(TreeNode* root) {
	if (root == NULL) return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);	
}

void postorder(TreeNode* root) {
	if (root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->val << " ";
}

void pathToLeaf(TreeNode* root, vector<int> path) {
	if (root->left == NULL && root->right == NULL) {
		for (auto i : path) cout << i << "=>";
		cout << root->val << "\n";
		return;
	}
	path.push_back(root->val);
	if (root->left != NULL) pathToLeaf(root->left, path);
	if (root->right != NULL) pathToLeaf(root->right, path);
}

int main() {
	int n, val;
	cin >> n >> val; n--;
	TreeNode* root = createNode(val);
	while (n--) {
		cin >> val;
		add(root, val);
	}
	preorder(root);
	cout << "\n";
	pathToLeaf(root, {});
	cout << "\n";
	return 0;	
}

// n root
// 7
// 9 10 14 12 16 2 5
//       9
//    2     10
//       5      14
//           12    16
