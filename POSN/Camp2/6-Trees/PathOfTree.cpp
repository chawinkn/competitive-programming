#include <bits/stdc++.h>
using namespace std;

struct node {
    int key;
    struct node* parent;
    struct node* leftChild;
    struct node* rightSibling;
};

struct node* create(int key) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->parent = NULL;
    node->leftChild = NULL;
    node->rightSibling = NULL;
    return node;
};

struct node* createNode(int key, struct node* parent) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->parent = parent;
    node->leftChild = NULL;
    node->rightSibling = NULL;
    if (node->parent != NULL) {
        if (node->parent->leftChild != NULL) {
            struct node* child = node->parent->leftChild;
            while (child->rightSibling != NULL) {
                child = child->rightSibling;
            }
            child->rightSibling = node;
        }
        else {
            node->parent->leftChild = node;
        }
    }
    return node;
};

struct node* arr[100001];

int main() {
    int n, r, p, c, t;
    cin >> n >> r;
    for (int i = 0; i <= 100000; i++) arr[i] = create(i);
    for (int i = 0; i < n; i++) {
        cin >> p >> c;
        arr[c] = createNode(c, arr[p]); // Node C -> Parent P
    }
    cin >> t;
    vector<int> ans;
    struct node* target = arr[t];
    while (target->parent != NULL) {
        ans.push_back(target->key);
        target = target->parent;
    }
    cout << r;
    for (int i = ans.size()-1; i >= 0; i--) cout << "/" << ans[i];
    return 0;
}

