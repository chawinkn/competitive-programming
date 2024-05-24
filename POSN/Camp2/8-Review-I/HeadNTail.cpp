#include <iostream>
#include <string.h>
using namespace std;

struct Node {
    int val;
    Node* next;
};

class List {
private:
    Node* head;
    Node* tail;
    int s;
public:
    List() {
        head = NULL;
        tail = NULL;
        s = 0;
    }

    void add_head(int val) {
        Node* dummy = new Node();
        dummy->val = val;
        dummy->next = NULL;
        s++;
        if (head == NULL && tail == NULL) {
            head = dummy;
            tail = dummy;
            return;
        }
        dummy->next = head;
        head = dummy;
    }

    void add_tail(int val) {
        Node* dummy = new Node();
        dummy->val = val;
        dummy->next = NULL;
        s++;
        if (head == NULL && tail == NULL) {
            head = dummy;
            tail = dummy;
            return;
        }
        tail->next = dummy;
        tail = dummy;
    }

    void remove_head() {
        Node* dummy = head;
        if (head == NULL) return;
        cout << head->val << "\n";
        s--;
        if (head == tail) {
            head = NULL;
            tail = NULL;
        }
        else {
            head = head->next;
        }
        delete dummy;
    }

    void remove_tail() {
        Node* dummy = tail;
        if (tail == NULL) return;
        cout << tail->val << "\n";
        s--;
        if (head == tail) {
            head = NULL;
            tail = NULL;
        }
        else {
            Node* curr = head;
            while (curr->next != tail) {
                curr = curr->next;
            }
            curr->next = NULL;
            tail = curr;
        }
        delete dummy;
    }

    void empty() {
        if (head == NULL) cout << "True\n";
        else cout << "False\n";
    }

    void clear() {
        head = NULL;
        tail = NULL;
        s = 0;
    }

    void size() {
        cout << s << "\n";
    }

    void debug() {
        cout << head->val << " " << tail->val << "\n";
    }
};

int main() {
    List l;
    string t, s;
    int n;
    while (cin >> t) {
        if (t == "exit") break;
        if (t == "add") {
            cin >> s >> n;
            if (s == "head") l.add_head(n);
            else l.add_tail(n);
        }
        else if (t == "remove") {
            cin >> s;
            if (s == "head") l.remove_head();
            else l.remove_tail();
        }
        else if (t == "empty?") l.empty();
        else if (t == "clear") l.clear();
        else if (t == "size") l.size();
//        l.debug();
    }
    return 0;
}
