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
    ListNode* swapPairs(ListNode* head) {
        ListNode* h = new ListNode();
        h->next = head;
        auto it = h;
        while (it) {
            auto nxt1 = it->next;
            if (!nxt1) break;
            // cout << nxt1->val << ' ';
            auto nxt2 = nxt1->next;
            if (!nxt2) break;
            // cout << nxt2->val << endl;
            auto nxt3 = nxt2->next;
            nxt1->next = nxt3;
            nxt2->next = nxt1;
            it->next = nxt2;
            it = nxt1;
        }
        return h->next;
    }
};