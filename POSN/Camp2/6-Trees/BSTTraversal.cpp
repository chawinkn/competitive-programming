#include <iostream>
#include <vector>
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

struct Node* insertBST(int key, struct Node* parent) {
    Node* next = parent;
    Node* curr = NULL;
    while (next != NULL) {
        curr = next;
        if (key <= next->key) next = next->leftChild;
        else next = next->rightChild;
    }
    if (key <= curr->key) return createLeftChild(key, curr);
    else return createRightChild(key, curr);
};

void preorder(struct Node* parent) {
    if (parent == NULL) return;
    cout << parent->key << " ";
    preorder(parent->leftChild);
    preorder(parent->rightChild);
}

void inorder(struct Node* parent) {
    if (parent == NULL) return;
    inorder(parent->leftChild);
    cout << parent->key << " ";
    inorder(parent->rightChild);
}

void postorder(struct Node* parent) {
    if (parent == NULL) return;
    postorder(parent->leftChild);
    postorder(parent->rightChild);
    cout << parent->key << " ";
}

int height=0;

void heightTree(struct Node* parent, int h) {
    if (parent == NULL) return;
    height = max(height, h);
    heightTree(parent->leftChild, h+1);
    heightTree(parent->rightChild, h+1);
}

map<int, Node*> arr;
//struct Node* arr[100001];

int main() {
    int r, n;
    vector<int> v;
    cin >> r;
    if (r != 0) {
        arr[r] = createNode(r);
        Node* root = arr[r];
        while (cin >> n) {
            if (n == 0) break;
            v.push_back(n);
        }
        for (auto i : v) arr[i] = insertBST(i, root);
        heightTree(root, 0);
        cout << "Height: " << height << "\n";
        cout << "Preorder: "; preorder(root); cout << "\n";
        cout << "Inorder: "; inorder(root); cout << "\n";
        cout << "Postorder: "; postorder(root); cout << "\n";
    }
    else cout << "What is emptier, my heart or this tree?";
    return 0;
}
