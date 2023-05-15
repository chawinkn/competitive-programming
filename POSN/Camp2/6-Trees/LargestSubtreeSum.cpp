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
//            parent->leftChild = node;
        }
    }
    return node;
};

//void postorder(struct node* parent) {
//    struct node* child = parent->leftChild;
//    while (child->rightSibling != NULL) {
//        postorder(child);
//        child = child->rightSibling;
//    }
//    cout << parent->key << " ";
//}

struct node* neg[100001];
struct node* pos[100001];

int main() {
    struct node* root;
    int n, r, p, c;
    cin >> r >> n;
    for (int i = 0; i <= 100000; i++) pos[i] = create(i);
    for (int i = 1; i <= 100000; i++) neg[i] = create(i);
    for (int i = 0; i < n-1; i++) {
        cin >> p >> c;
        if (p >= 0) {
            if (c >= 0) pos[c] = createNode(c, pos[p]); // Node C -> Parent P
            else neg[-c] = createNode(c, pos[p]);
        }
        else {
            if (c >= 0) pos[c] = createNode(c, neg[-p]);
            else neg[-c] = createNode(c, neg[-p]);
        }
    }
    cout << pos[3]->leftChild->rightSibling->key << "\n";
//    if (r >= 0) {
////        cout << pos[r]->key;
//        postorder(pos[r]);
//    }
//    else {
////        cout << neg[-r]->key << "\n";
////        cout << neg[-r]->leftChild->key << "\n";
////        cout << neg[-r]->leftChild->leftChild->key << "\n";
//        postorder(neg[-r]);
//    }
    return 0;
}

