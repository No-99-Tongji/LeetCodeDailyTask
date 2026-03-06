#include <iostream>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    void print_list(Node* h) {
        while (h) {
            cout << h->val << ' ';
            h = h->next;
        }
        cout << endl;
    }

    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // print_list(head);
        Node *t1 = new Node(0);
        Node *t2 = new Node(0);
        Node* h = new Node(head->val);
        t1->next = h, t2->next = head;
        while (head) {
            // cout << head->val << endl;
            head = head->next;
            if (head)
                h->next = new Node(head->val);
            else h->next = nullptr;
            h = h->next;
        }
        // print_list(t1->next);
        h = t1->next, head = t2->next;
        while (h) {
            Node *it1 = t1->next;
            Node *it2 = t2->next;
            Node *end2 = head->random;
            while (it2 != end2) {
                it1 = it1->next, it2 = it2->next;
            }
            h->random = it1;
            h = h->next, head = head->next;
        }
        return t1->next;
    }
};