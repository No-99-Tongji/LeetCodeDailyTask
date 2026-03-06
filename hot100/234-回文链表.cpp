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
    bool isPalindrome(ListNode* head) {
        auto itA = head, itB = head;
        while (itB) {
            itA = itA->next;
            itB = itB->next;
            if (itB == nullptr) break;
            itB = itB->next;
        }
        itB = itA->next;

        ListNode* t = new ListNode();
        while (itB) {
            auto next = itB->next;
            itB->next = t->next;
            t->next = itB;
            itB = next;
        }
        itB = t->next;
        while (itB) {
            if (itA->val != itB->val) return false;
            itA = itA->next;
            itB = itB->next;
        }
        return true;
    }
};