#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node {
    int val;
    Node* parent;
    Node* leftChild;
    Node* rightChild;
};

Node* createNode(int val) {
    Node* dummy = new Node();
    dummy->val = val;
    dummy->parent = NULL;
    dummy->leftChild = NULL;
    dummy->rightChild = NULL;
    return dummy;
}

Node* insert(int val, Node* parent) {
    Node* dummy = createNode(val);
    if (parent == NULL) return dummy;
    Node* x = parent;
    Node* y;
    while (x != NULL) {
        y = x;
        if (val <= x->val) x = x->leftChild;
        else x = x->rightChild;
    }
    if (val <= y->val) y->leftChild = dummy;
    else y->rightChild = dummy;
    return dummy;
}

void preorder(Node* parent) {
    if (parent == NULL) return;
    cout << parent->val << "\n";
    preorder(parent->leftChild);
    preorder(parent->rightChild);
}

map<int, Node*> arr;
vector<pair<int, Node*>> temp;

void inorder(Node* parent) {
    if (parent == NULL) return;
    inorder(parent->leftChild);
    temp.push_back({parent->val, parent});
    delete parent;
    inorder(parent->rightChild);
}

void del(Node* parent) {
    inorder(parent);
    for (auto i : temp) {
        arr[i.first] = insert(i.first, i.second);
    }
    temp.clear();
}

int main() {
    int n, found=0;
    Node* root;
    while (cin >> n) {
        if (n == 0) {
            cin >> n;
            del(arr[n]);
            preorder(root);
            break;
        }
        if (!found) {
            arr[n] = createNode(n);
            root = arr[n];
            found = 1;
        }
        else arr[n] = insert(n, root);
    }
    return 0;
}
