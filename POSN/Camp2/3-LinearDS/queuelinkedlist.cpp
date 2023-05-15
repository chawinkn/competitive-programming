#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
};

class Queue {
private:
    Node* head;
    Node* rear;
public:
    Queue() {
        head = NULL;
        rear = NULL;
    }

    void enqueue(int val) {
        Node* dummy = new Node();
        dummy->val = val;
        dummy->next = NULL;
        if (head == NULL && rear == NULL) {
            head = rear = dummy;
            return;
        }
        rear->next = dummy;
        rear = dummy;
    }

    void dequeue() {
        Node* dummy = head;
        if (head == NULL) return;
        if (head == rear) {
            head = rear = NULL;
        }
        else head = head->next;
        cout << dummy->val << "\n";
        delete dummy;
    }

    void peek() {
        if (head != NULL) cout << head->val << "\n";
    }

    void empty() {
        if (head == NULL) cout << "Empty\n";
        else cout << "Not empty\n";
    }
};

int main() {
    Queue q;
    string t;
    int n;
    while (1) {
        cin >> t;
        if (t == "enqueue") {
            cin >> n;
            q.enqueue(n);
        }
        else if (t == "dequeue") q.dequeue();
        else if (t == "peek") q.peek();
        else if (t == "empty?") q.empty();
        else break;
    }
}
