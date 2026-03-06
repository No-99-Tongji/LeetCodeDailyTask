#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    void print_list(ListNode* l) {
        while (l) {
            cout << l->val << ' ';
            l = l->next;
        }
        cout << endl;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *t = new ListNode();

        while (head) {
            auto next = head->next;
            head->next = t->next;
            t->next = head;
            head = next;
        }
        // print_list(t->next);
        auto it = t;
        for (int i = 0; i < n-1; i++) {
            it = it->next;
        }
        auto temp = it->next;
        cout << temp->val << endl;
        it->next = it->next->next;
        delete temp;
        // print_list(t->next);


        head = t->next;
        t->next = nullptr;
        while (head) {
            auto next = head->next;
            head->next = t->next;
            t->next = head;
            head = next;
        }
        // print_list(t->next);
        return t->next;
    }
};

int main() {


    return 0;
}