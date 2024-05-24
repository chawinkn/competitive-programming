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

void createNode(int key, struct node* parent) {
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
};

struct node* arr[100001];

int main() {
    int n, m, p, c;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) arr[i] = create(i);
    for (int i = 0; i < m; i++) {
        cin >> p >> c;
        createNode(c, arr[p]); // Node C -> Parent P
    }
    int cnt=0;
    for (int i = 1; i <= n; i++) {
        if (arr[i]->leftChild == NULL) cnt++;
    }
    cout << cnt;
    return 0;
}
