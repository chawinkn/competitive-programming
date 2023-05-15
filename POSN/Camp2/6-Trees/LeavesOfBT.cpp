#include <iostream>
#include <map>
using namespace std;

struct Node {
    int key;
    Node* parent;
    Node* leftChild;
    Node* rightChild;
};

struct Node* createNode(int key) {
    Node* dummy = new Node();
    dummy->key = key;
    dummy->parent = NULL;
    dummy->leftChild = NULL;
    dummy->rightChild = NULL;
    return dummy;
};

struct Node* createLeftChild(int key, struct Node* parent) {
    Node* dummy = createNode(key);
    dummy->parent = parent;
    parent->leftChild = dummy;
    return dummy;
};

struct Node* createRightChild(int key, struct Node* parent) {
    Node* dummy = createNode(key);
    dummy->parent = parent;
    parent->rightChild = dummy;
    return dummy;
};

int lc=0, rc=0;

void preorder(struct Node* parent) {
    if (parent == NULL) return;
    if (parent->leftChild == NULL && parent->rightChild == NULL) {
        if (parent->parent->leftChild == parent) lc++;
        else if (parent->parent->rightChild == parent) rc++;
    }
    preorder(parent->leftChild);
    preorder(parent->rightChild);
    cout << parent->key << " ";
}

map<int, Node*> arr;
//struct Node* arr[100001];

int main() {
    int r, n, p, c;
    char t;
    cin >> r >> n;
    arr[r] = createNode(r);
    for (int i = 0; i < n; i++) {
        cin >> p >> c >> t;
        if (t == 'L') arr[c] = createLeftChild(c, arr[p]);
        else arr[c] = createRightChild(c, arr[p]);
    }
    struct Node* root = arr[r];
    preorder(root);
    cout << lc << " " << rc;
    return 0;
}
