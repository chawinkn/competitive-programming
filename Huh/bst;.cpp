#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* leftChild;
    Node* rightChild;
};

struct Node* createNode(int key) {
    Node* dummy = new Node();
    dummy->key = key;
    dummy->leftChild = NULL;
    dummy->rightChild = NULL;
    return dummy;
};

struct Node* insertBST(int key, struct Node* node) {
    if (node == NULL) return createNode(key);
    if (key < node->key) node->leftChild = insertBST(key, node->leftChild);
    else node->rightChild = insertBST(key, node->rightChild);
	return node;
};

// void insertBST(int key, struct Node* node) {
// 	Node* newNode = createNode(key);
// 	Node* next = node;
// 	Node* curr = NULL;
// 	while (next != NULL) {
// 		curr = next;
// 		if (key < next->key) next = next->leftChild;
// 		else next = next->rightChild;
// 	}
// 	if (key < curr->key) curr->leftChild = newNode;
// 	else curr->rightChild = newNode;
// }

void preorder(struct Node* node) {
    if (node == NULL) return;
    cout << node->key << " ";
    preorder(node->leftChild);
    preorder(node->rightChild);
}

void inorder(struct Node* node) {
    if (node == NULL) return;
    inorder(node->leftChild);
    cout << node->key << " ";
    inorder(node->rightChild);
}

void postorder(struct Node* node) {
    if (node == NULL) return;
    postorder(node->leftChild);
    postorder(node->rightChild);
    cout << node->key << " ";
}

int height=0;

void heightTree(struct Node* node, int h) {
    if (node == NULL) return;
    height = max(height, h);
    heightTree(node->leftChild, h+1);
    heightTree(node->rightChild, h+1);
}

int main() {
    int r, n;
    cin >> r;
    if (r != 0) {
        Node* root = createNode(r);
        while (cin >> n) {
            if (n == 0) break;
            insertBST(n, root);
        }
        heightTree(root, 0);
        cout << "Height: " << height << "\n";
        cout << "Preorder: "; preorder(root); cout << "\n";
        cout << "Inorder: "; inorder(root); cout << "\n";
        cout << "Postorder: "; postorder(root); cout << "\n";
    }
    else cout << "What is emptier, my heart or this tree?";
    return 0;
}