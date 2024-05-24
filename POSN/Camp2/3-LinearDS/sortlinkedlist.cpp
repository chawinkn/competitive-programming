#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
};

class List {
    Node* head;
public:
    List() {
        head = NULL;
    }
    void push(int val) {
        Node* dummy = new Node();
        dummy->val = val;
        if (head == NULL) {
            head = dummy;
            return;
        }
        Node* curr = head;
        if (val <= curr->val) {
            dummy->next = curr;
            head = dummy;
            return;
        }
        while (curr->next != NULL) {
            if (val >= curr->val && val <= curr->next->val) {
                dummy->next = curr->next;
                curr->next = dummy;
                return;
            }
            curr = curr->next;
        }
        if (val >= curr->val) {
            curr->next = dummy;
            dummy->next = NULL;
            return;
        }
    }
    void print() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->val << "\n";
            curr = curr->next;
        }
    }
};

int main() {
    List l;
    int n;
    while (1) {
        cin >> n;
        if (n == -1) break;
        l.push(n);
    }
    l.print();
    return 0;
}
