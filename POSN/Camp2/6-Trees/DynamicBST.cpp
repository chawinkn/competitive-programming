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

struct Node* findBST(int key, struct Node* parent) {
    if ((parent == NULL) || (key == parent->key)) return parent;
    if (key <= parent->key) return parent->leftChild;
    else return parent->rightChild;
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
    Node* root;
    int n, a, t, founded=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t == 1) {
            cin >> a;
            if (!founded) {
                arr[a] = createNode(a);
                root = arr[a];
                founded = 1;
            }
            else arr[a] = insertBST(a, root);
        }
        else if (t == 2) {
            cin >> a;
            Node* dummy = findBST(a, root);
            if (dummy != NULL) cout << "true\n";
            else cout << "false\n";
        }
        else if (t == 3) {
            preorder(root);
            cout << "\n";
        }
        else if (t == 4) {
            postorder(root);
            cout << "\n";
        }
        else if (t == 5) {
            inorder(root);
            cout << "\n";
        }
    }
    return 0;
}
